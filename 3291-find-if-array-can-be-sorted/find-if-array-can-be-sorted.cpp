class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int a = INT_MIN, b = INT_MIN;
        int x = nums[0], y = nums[0];
        int prev_count = __builtin_popcount(nums[0]);

        for (int i = 1; i < nums.size(); i++) {
            int current_count = __builtin_popcount(nums[i]);
            
            if (current_count == prev_count) {
                x = min(x, nums[i]);
                y = max(y, nums[i]);
            } else {
                if (x < b) {
                    return false;
                }
                a = x;
                b = y;
                x = nums[i];
                y = nums[i];
                prev_count = current_count;
            }
        }
        if (x < b) {
            return false;
        }

        return true;
    }
};