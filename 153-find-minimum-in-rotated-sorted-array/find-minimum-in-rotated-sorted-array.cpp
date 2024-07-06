class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0]<=nums[nums.size()-1]){
            return nums[0];
        }
        int l = 0;
        int h = nums.size()-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid]>nums[mid+1]){
                return nums[mid+1];
            }
            else if(nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            else if(nums[l]<nums[mid]){
                l = mid+1;
            }
            else{
                h = mid-1;
            }
        }
        return -1;
    }
};