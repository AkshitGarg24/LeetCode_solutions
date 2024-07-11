class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0;
        int h = 0;
        int ans = INT_MAX;
        int sum = 0;
        while (h < nums.size()) {
            sum += nums[h];
            if(sum>=target){
                ans = min(ans,h-l+1);
                while(sum-nums[l]>=target){
                    sum -= nums[l];
                    l++;
                    ans = min(ans,h-l+1);
                }
            }
            h++;
        }
        if(ans==INT_MAX) return 0;
        return ans;
    }
};