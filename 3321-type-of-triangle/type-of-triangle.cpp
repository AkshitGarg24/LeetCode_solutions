class Solution {
    bool checkTriangle(vector<int> &nums){
        if(nums[0] + nums[1]>nums[2] && nums[0]+nums[2]>nums[1] && nums[1]+nums[2]>nums[0]){
            return true;
        }
        return false;
    }
public:
    string triangleType(vector<int>& nums) {
        if(!checkTriangle(nums)){
            return "none";
        }
        if(nums[0]==nums[1] && nums[1]==nums[2]){
            return "equilateral";
        }
        if(nums[0]==nums[1] || nums[1]==nums[2] || nums[0]==nums[2]){
            return "isosceles";
        }
        return "scalene";
    }
};