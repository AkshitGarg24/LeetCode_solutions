class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()<=1){
            return nums.size();
        }
        int ans = 1;
        int cnt = 1;
        bool check = false; 
        for(int i = 1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                cnt = 1;
            }
            else if(!check){
                if(nums[i]<nums[i-1]){
                    cnt++;
                    ans = max(ans,cnt);
                } else {
                    cnt = 2;
                    check = true;
                    ans = max(ans,cnt);
                }
            } else {
                if(nums[i]>nums[i-1]){
                    cnt++;
                    ans = max(ans,cnt);
                } else {
                    cnt = 2;
                    check = false;
                    ans = max(ans,cnt);
                }
            }
        }
        return ans;
    }
};