class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        int ans = -1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>target){
                ans = mid;
                h = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        if(ans==-1){
            return nums.size();
        }
        return ans;
    }
};