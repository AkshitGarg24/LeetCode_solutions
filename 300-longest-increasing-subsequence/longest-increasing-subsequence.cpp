class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()+1,0);
        vector<int> temp(nums.size()+1);
        for(int i=1;i<nums.size()+1;i++){
            for(int j=i;j<nums.size()+1;j++){
                temp[j] = 0;
                temp[j] = max(temp[j],dp[j]);
                if(j==nums.size() || nums[i-1]<nums[j]){
                    temp[j] = max(temp[j],1 + dp[i-1]);
                }
            }
            dp = temp;
        }
        return dp[nums.size()];
    }
};