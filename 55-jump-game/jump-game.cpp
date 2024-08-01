class Solution {
public:
    bool canJump(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>ans){
                return false;
            }
            ans = max(ans,i+nums[i]);
        }
        return true;
    }
};