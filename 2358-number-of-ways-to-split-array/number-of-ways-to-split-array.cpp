class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int ans = 0;
        long long sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        long long x = 0;
        for(int i=0;i<nums.size()-1;i++){
            x += nums[i];
            if(x>=sum-x){
                ans++;
            }
        }
        return ans;
    }
};