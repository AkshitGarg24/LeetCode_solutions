class Solution {
public:
    int check(vector<int> &dp,vector<int> &nums,int i){
        if(i==0){
            return nums[0];
        }
        if(i==1){
            return max(nums[0],nums[1]);
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int a  = nums[i] + check(dp,nums,i-2);
        int b = check(dp,nums,i-1);
        return dp[i] = max(a,b);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return check(dp,nums,nums.size()-1);
    }
};