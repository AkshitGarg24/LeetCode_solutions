class Solution {
public:
    int check(vector<int> &nums,int i,int a,vector<vector<int>> &dp){
        if(i<0){
            return 0;
        }
        if(dp[i][a]!=-1){
            return dp[i][a];
        }
        int ans = 0;
        ans = max(ans,check(nums,i-1,a,dp));
        int maxi;
        if(a==nums.size()){
            maxi = INT_MAX;
        } else {
            maxi = nums[a];
        }
        if(nums[i]<maxi){
            ans = max(ans,1 + check(nums,i-1,i,dp));
        }
        return dp[i][a] = ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int> (nums.size()+1,-1));
        return check(nums,nums.size()-1,nums.size(),dp);
    }
};