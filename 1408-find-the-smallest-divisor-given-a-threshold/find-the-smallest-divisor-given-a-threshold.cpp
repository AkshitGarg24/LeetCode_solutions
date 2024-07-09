class Solution {
public:
    int func(vector<int> &nums, int x){
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += ceil((double)nums[i]/x);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int abc = -1;
        for(auto x : nums){
            abc = max(abc,x);
        }
        int l = 1;
        int h = abc;
        int ans;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(func(nums,mid)<=threshold){
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