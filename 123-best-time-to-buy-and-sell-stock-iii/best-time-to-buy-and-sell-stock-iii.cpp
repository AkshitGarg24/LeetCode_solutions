class Solution {
public:
    int check(vector<int> &nums,int i,bool buy,int cnt,vector<vector<vector<int>>> &dp){
        if(cnt==0){
            return 0;
        }
        if(i==nums.size()-1){
            if(buy){
                return nums[i];
            }
            return 0;
        }
        if(dp[i][buy][cnt]!=-1){
            return dp[i][buy][cnt];
        }
        int ans = 0;
        ans = max(ans,check(nums,i+1,buy,cnt,dp));
        if(!buy){
            ans = max(ans,-nums[i] + check(nums,i+1,true,cnt,dp)); 
        }
        else {
            ans = max(ans,nums[i] + check(nums,i+1,false,cnt-1,dp));
        }
        return dp[i][buy][cnt] = ans;
    }
    int maxProfit(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(),vector<vector<int>> (2,vector<int> (3,-1)));
        return check(nums,0,false,2,dp);
    }
};