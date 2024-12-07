class Solution {
public:
    int check(vector<int> &nums,int mid){
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%mid==0){
                ans += nums[i]/mid-1;
            } else {
                ans += nums[i]/mid;
            }
        }
        return ans;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1;
        int h = INT_MIN;
        for(int i=0;i<nums.size();i++){
            h = max(h,nums[i]);
        }
        while(l<=h){
            int mid = l + (h-l)/2;
            if(check(nums,mid)<=maxOperations){
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};