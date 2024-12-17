class Solution {
public:

    bool check(vector<int> &nums,int sum,int cnt,int n,vector<vector<int>> &dp){
        if(cnt==sum-cnt){
            return true;
        }
        if(n==0){
            cnt += nums[n];
            if(cnt==sum-cnt){
                return true;
            } else {
                return false;
            }
        }
        if(dp[n][cnt]!=-1){
            return dp[n][cnt];
        }
        bool a = check(nums,sum,cnt,n-1,dp);
        bool b = check(nums,sum,cnt+nums[n],n-1,dp);
        return dp[n][cnt] = a||b;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        vector<vector<int>> dp(nums.size(),vector<int> (sum,-1));
        return check(nums,sum,0,nums.size()-1,dp);
    }
};