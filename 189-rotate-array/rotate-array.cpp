class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            nums[i] = nums[i] ^ nums[j];
            nums[j] = nums[i] ^ nums[j];
            nums[i] = nums[i] ^ nums[j];
            i++;
            j--;
        }
        i = 0;
        j = k - 1;
        while (i < j) {
            nums[i] = nums[i] ^ nums[j];
            nums[j] = nums[i] ^ nums[j];
            nums[i] = nums[i] ^ nums[j];
            i++;
            j--;
        }
        i = k;
        j = nums.size() - 1;
        while (i < j) {
            nums[i] = nums[i] ^ nums[j];
            nums[j] = nums[i] ^ nums[j];
            nums[i] = nums[i] ^ nums[j];
            i++;
            j--;
        }
    }
};