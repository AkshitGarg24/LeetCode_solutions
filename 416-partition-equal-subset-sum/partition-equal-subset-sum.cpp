class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        vector<int> dp(sum,-1);
        for(int i=0;i<sum;i++){
            int cnt = i;
            cnt += nums[0];
            if(cnt==sum-cnt){
                dp[i] = true;
            } else {
                dp[i] = false;
            }
        }
        vector<int> temp(sum);
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<sum;j++){
                if(j==sum-j){
                    temp[j] = true;
                    continue;
                }
                bool a = dp[j];
                bool b = false;
                if(j+nums[i]<sum){
                    b = dp[j+nums[i]];
                }
                temp[j]  = a||b;
            }
            dp = temp;
        }
        return dp[0];
    }
};