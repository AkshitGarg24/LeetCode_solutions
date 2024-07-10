class Solution {
public:
    int func(vector<int> &nums, int mid){
        int days = 1, load = 0;
        for(int i=0;i<nums.size();i++){
            load += nums[i];
            if(load>mid){
                load = nums[i];
                days++;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int l = *max_element(nums.begin(),nums.end());
        int h =  accumulate(nums.begin(),nums.end(),0);
        int ans;
        while(l<=h){
            int mid = l+ (h-l)/2;
            if(func(nums,mid)<=days){
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