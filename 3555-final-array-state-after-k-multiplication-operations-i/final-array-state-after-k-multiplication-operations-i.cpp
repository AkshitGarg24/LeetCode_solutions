class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--){
            int min = nums[0];
            int idx = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]<min){
                    min = nums[i];
                    idx = i;
                }
            }
            nums[idx] *= multiplier;
        }
        return nums;
    }
};