class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0,sum = 0;
        unordered_set<int> s;
        for(int i=0;i<banned.size();i++){
            s.insert(banned[i]);
        }
        for(int i=1;i<=n;i++){
            if(s.find(i)==s.end() && sum+i<=maxSum){
                ans++;
                sum += i;
            }
        }
        return ans;
    }
};