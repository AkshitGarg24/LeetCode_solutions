class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int x = INT_MIN;
        for(int i=0;i<nums.size();i++){
            x = max(x,nums[i]);
        }
        int count = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=x){
                count = 0;
            }
            if(nums[i]==x){
                count++;
                ans = max(ans,count);
            }
        }
        return ans;
    }
};