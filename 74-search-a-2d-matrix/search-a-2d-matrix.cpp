class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int row = nums.size()-1;
        int column = nums[0].size()-1;
        if(target<nums[0][0] || target>nums[row][column]){
            return false;
        }
        int l1 = 0;
        int h1 = row;
        int ans = -1;
        while(l1<=h1){
            int mid = l1 + (h1-l1)/2;
            if(nums[mid][0]<=target){
                ans = mid;
                l1 = mid+1;
            }
            else{
                h1 = mid-1;
            }
        }
        int l2 = 0;
        int h2 = nums[0].size()-1;
        while(l2<=h2){
            int mid = l2 + (h2-l2)/2;
            if(nums[ans][mid]==target){
                return true;
            }
            else if(nums[ans][mid]>target){
                h2 = mid-1;
            }
            else {
                l2 = mid+1;
            }
        }
        return false;
    }
};