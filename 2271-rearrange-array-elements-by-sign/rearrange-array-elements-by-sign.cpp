class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int i = 0;
        int j = 1;
        for(int x=0;x<nums.size();x++){
            if(nums[x]>0){
                ans[i] = nums[x];
                i = i + 2;
            }
            else {
                ans[j] =  nums[x];
                j = j + 2;
            }
        }
        return ans;
    }
};