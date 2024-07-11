class Solution {
public:
    int func(vector<int>& nums, int mid) {
        int ans = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > mid) {
                ans++;
                sum = nums[i];
            }
        }
        return ans;
    }
    int splitArray(vector<int>& nums, int m) {
        int l = *max_element(nums.begin(), nums.end());
        int h = accumulate(nums.begin(), nums.end(), 0);
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (func(nums, mid) <= m) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};