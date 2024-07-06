class Solution {
public:
    int pivot(vector<int>& nums, int l, int h) {
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] < nums[mid - 1]) {
                return mid - 1;
            } else if (nums[mid] > nums[l]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return -1;
    }
    int bs(vector<int>& nums, int l, int h, int target) {
        while (l <= h) {
            int mid = l + (h - l) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        if (nums[nums.size() - 1] >= nums[0]) {
            return bs(nums, 0, nums.size() - 1, target);
        }
        int idx;
        int l = 0;
        int h = nums.size() - 1;
        idx = pivot(nums, 0, h);

        int l1 = 0;
        int h1 = idx;
        int l2 = idx + 1;
        int h2 = nums.size() - 1;
        if (target >= nums[l1]) {
            if (target > nums[h1]) {
                return -1;
            }
            l = l1;
            h = h1;
        } else {
            if (target < nums[l2]) {
                return -1;
            }
            l = l2;
            h = h2;
        }
        return bs(nums, l, h, target);
    }
};