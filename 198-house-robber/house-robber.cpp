class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        int a = nums[0];
        int b = max(nums[0],nums[1]);
        int ans;
        for(int i=2;i<nums.size();i++){
            ans = max(nums[i]+a,b);
            a = b;
            b = ans;
        }
        return ans;
    }
};