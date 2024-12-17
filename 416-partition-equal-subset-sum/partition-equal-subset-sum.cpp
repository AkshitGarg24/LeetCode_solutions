class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        vector<vector<int>> dp(nums.size(),vector<int> (sum,-1));
        for(int i=0;i<sum;i++){
            int cnt = i;
            cnt += nums[0];
            if(cnt==sum-cnt){
                dp[0][i] = true;
            } else {
                dp[0][i] = false;
            }
        }
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<sum;j++){
                if(j==sum-j){
                    dp[i][j] = true;
                    continue;
                }
                bool a = dp[i-1][j];
                bool b = false;
                if(j+nums[i]<sum){
                    b = dp[i-1][j+nums[i]];
                }
                dp[i][j]  = a||b;
            }
        }
        return dp[nums.size()-1][0];
    }
};