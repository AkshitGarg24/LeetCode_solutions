class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0];
        int cnt = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                cnt += nums[i];
                ans = max(ans,cnt);
            } else {
                cnt = nums[i];
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};