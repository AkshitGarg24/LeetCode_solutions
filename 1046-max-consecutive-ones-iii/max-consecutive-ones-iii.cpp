class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int cnt = 0;
        int l = 0,h=0;
        while(h<nums.size()){
            if(nums[h]==0){
                cnt++;
            }
            if(cnt>k){
                if(nums[l]==0){
                    cnt--;
                }
                l++;
            }  
            if(cnt<=k){
                ans = max(ans,h-l+1);
            }
            h++;
        }
        return ans;
    }
};