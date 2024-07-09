class Solution {
public:
    bool func(vector<int> &nums, int mid, int m, int k){
        int x = k ;
        for(int i=0;i<nums.size();i++){
            int a = nums[i];
            
            if(m==0){
                return true;
            }
            if(ceil((double)a/mid)==1){
                x--;
            }

            else{
                x = k;
            }
            if(x==0){
                m--;
                x=k;
            }
            
        }
        return m==0;
    }
    int minDays(vector<int>& nums, int m, int k) {
        // if(nums.size()<m*k){
        //     return -1;
        // }
        // if(nums.size()==m*k){
        //     return *max_element(nums.begin(),nums.end());
        // }
        int ans = -1;
        int l = 1;
        int h = *max_element(nums.begin(),nums.end());
        while(l<=h){
            int mid = l + (h-l)/2;
            if(func(nums,mid,m,k)){
                ans = mid;
                h = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
};