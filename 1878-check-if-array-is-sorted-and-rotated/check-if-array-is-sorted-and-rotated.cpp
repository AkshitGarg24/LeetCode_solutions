class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums.size()==1) return true;
        if(nums[nums.size()-1]>nums[0]){
            for(int i=1;i<nums.size();i++){
                if(nums[i]<nums[i-1]){
                    return false;
                }
            }
            return true;
        }
        int i = 1;
        while(i<nums.size() && nums[i]>=nums[i-1]){
            i++;
        }
        if(i==nums.size()) return true;
        for(int j = i+1; j<nums.size();j++){
            if(nums[j]>=nums[j-1] && nums[j]<=nums[0]){
                continue;
            } else {
                return false;
            }
        }
        return true;
    }
};