class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int l = 0, h = nums.size()-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid]<0){
                l = mid+1;
            } else {
                h = mid-1;
            }
        }
        int neg = l;
        l = 0, h = nums.size()-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid]>0){
                h = mid-1;
            } else {
                l = mid+1;
            }
        }
        int pos = nums.size()-h-1;
        return max(pos,neg);
    }
};