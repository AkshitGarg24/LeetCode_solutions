class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            int l = 0;
            int h = nums[0].size()-1;
            while(l<=h){
                int mid = l+(h-l)/2;
                if(nums[i][mid]==target){
                    return true;
                }
                else if(nums[i][mid]>target){
                    h = mid-1;
                }
                else {
                    l= mid+1;
                }
            }
        }
        return false;
    }
};