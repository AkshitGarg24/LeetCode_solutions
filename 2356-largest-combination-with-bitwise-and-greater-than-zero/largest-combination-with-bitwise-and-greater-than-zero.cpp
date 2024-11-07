class Solution {
public:
    int largestCombination(vector<int>& nums) {
        int ans = 0;
        
        while(true){
            bool check = false;
            int cnt = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]>0){
                    check = true;
                    cnt += (nums[i]&1);
                    nums[i] = nums[i]>>1;
                }
                
            }
            ans = max(ans,cnt);
            if(check==false){
                break;
            }
        }
        
        return ans;        
    }
};