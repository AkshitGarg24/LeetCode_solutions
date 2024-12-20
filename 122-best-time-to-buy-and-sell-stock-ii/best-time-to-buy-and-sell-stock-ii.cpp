class Solution {
public:
    int maxProfit(vector<int>& nums) {
        vector<int> dp (2,0);
        vector<int> temp(2);
        dp[0] = 0;
        dp[1] = nums[nums.size()-1];
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=1;j>=0;j--){
                temp[j] = 0;
                temp[j] = max(temp[j],dp[j]);
                if(j==0){
                    temp[j] = max(temp[j],dp[1]-nums[i]);
                } else {
                    temp[j] = max(temp[j],nums[i] + dp[0]);
                }
            }
            dp = temp;
        }
        return dp[0];
    }
};