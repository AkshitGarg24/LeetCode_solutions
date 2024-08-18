class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> ans(nums.size()+1,-1);
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0 && nums[i]<nums.size()+1){
                ans[nums[i]] = 1;
            }
        }
        for(int i=1;i<ans.size();i++){
            if(ans[i]==-1){
                return i;
            }
        }
        return nums.size()+1;
    }
};