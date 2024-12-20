class Solution {
public:
    int check(vector<int> &nums,int i,bool buy,vector<vector<int>> &dp){
        if(i>=nums.size()){
            return 0;
        }
        if(i==nums.size()-1){
            if(buy){
                return nums[i];
            }
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int ans = 0;
        ans = max(ans,check(nums,i+1,buy,dp));
        if(!buy){
            ans = max(ans,-nums[i] + check(nums,i+1,!buy,dp)); 
        }
        else {
            ans = max(ans,nums[i] + check(nums,i+2,!buy,dp));
        }
        return dp[i][buy] = ans;
    }
    int maxProfit(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int> (2,-1));
        return check(nums,0,false,dp);
    }
};