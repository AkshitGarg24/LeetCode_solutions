class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1){
            return nums.size();
        }
        unordered_set<int> s;
        for(auto x : nums){
            s.insert(x);
        }
        int ans = 1;
        for(auto x : s){
            if(s.find(x-1)==s.end()){
                int cnt = 1;
                int num = x;
                while(s.find(num+1)!=s.end()){
                    cnt++;
                    num++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};