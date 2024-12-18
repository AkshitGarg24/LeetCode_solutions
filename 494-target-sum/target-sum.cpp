class Solution {
public:
    int check(vector<int> &nums,int target,int i){
        if(i==0){
            int ans = 0;
            int a = target-nums[0];
            if(a==0){
                ans++;
            }
            a = target + nums[0];
            if(a==0){
                ans++;
            }
            return ans;
        }
        int a = check(nums,target-nums[i],i-1);
        int b = check(nums,target+nums[i],i-1);
        return a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return check(nums,target,nums.size()-1);
    }
};