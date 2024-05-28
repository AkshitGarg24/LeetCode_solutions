class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        if(k==0){
            int ans = 0;
            int count = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i]==1){
                    count++;
                    ans = max(ans,count);
                } else {
                    count  = 0;
                }
            }
            return ans;
        }
        int a = k;
        int l = 0;
        int r = 0;
        int maxlen = 0;
        int idx = 0;
        while(r<nums.size()){
            if(nums[r]==1){
                maxlen = max(maxlen,r-l+1);
                r++;
            } else {
                if(a>0){
                    a--;
                    idx = min(idx,r);
                    maxlen = max(maxlen,r-l+1);
                    r++;
                } else {
                    l = idx+1;
                    a = k;
                    idx = INT_MAX;
                    r = l;
                }
            }
        }
        return maxlen;
    }
};