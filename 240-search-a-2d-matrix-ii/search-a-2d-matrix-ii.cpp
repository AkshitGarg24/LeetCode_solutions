class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) {
        int row = 0, column = nums[0].size()-1;
        while(row<nums.size() && column>=0){
            if(nums[row][column]==target){
                return true;
            }
            else if(nums[row][column]>target){
                column--;
            }
            else{
                row++;
            }
        }
        return false;
    }
};