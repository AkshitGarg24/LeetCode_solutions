class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans;
        int diff = INT_MAX;
        for(int x=0;x<nums.size()-2;x++){
            int i = x+1;
            int j = nums.size()-1;
            while(i<j){
                int sum = nums[x]+nums[i]+nums[j];
                if(sum==target){
                    return sum;
                }
                if(abs(sum-target)<diff){
                    diff = abs(sum-target);
                    ans = sum;
                }
                if(sum>target){
                    j--;
                } else {
                    i++;
                }
            }
        }
        return ans;
    }
};