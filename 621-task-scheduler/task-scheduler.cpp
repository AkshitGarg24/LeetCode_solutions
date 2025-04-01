class Solution {
public:
    int leastInterval(vector<char>& tasks, int cooldown) {
        int taskFreq[26] = {0}; 
        int maxTaskCount = 0;  

        for (int i = 0; i < tasks.size(); i++) {
            taskFreq[tasks[i] - 'A']++;
            maxTaskCount = max(maxTaskCount, taskFreq[tasks[i] - 'A']);
        }

        int requiredTime = (maxTaskCount - 1) * (cooldown + 1);

        for (int i = 0; i < 26; i++) {
            if (taskFreq[i] == maxTaskCount) {
                requiredTime++;
            }
        }

        return max((int)tasks.size(), requiredTime);
    }
};
