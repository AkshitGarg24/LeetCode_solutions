class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        int ans = INT_MAX;
        while (l <= h) {
            int mid = l + (h - l) / 2;
            ans = min(ans, nums[mid]);
            if (nums[mid] == nums[l] && nums[mid] == nums[h]) {
                l++;
                h--;
                continue;
            } else if (nums[l] <= nums[mid]) {
                ans = min(ans, nums[l]);
                l = mid + 1;
            } else {
                ans = min(ans, nums[mid + 1]);
                h = mid - 1;
            }
        }
        return ans;
    }
};