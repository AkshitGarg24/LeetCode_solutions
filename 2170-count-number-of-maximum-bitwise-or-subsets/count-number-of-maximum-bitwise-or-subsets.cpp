class Solution {
public:
    void check(vector<int> &nums, int &ans, int i, int x, int calculate) {
        if (i == nums.size()) {
            if (calculate == x) {
                ans++;
            }
            return;
        }
        check(nums, ans, i + 1, x, calculate);
        check(nums, ans, i + 1, x, calculate | nums[i]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int x = 0;
        for(int i=0;i<nums.size();i++){
            x |= nums[i];
        }
        int ans = 0;
        int calculate = 0;
        check(nums,ans,0,x,calculate);
        return ans;
    }
};