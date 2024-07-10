class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        int i = 1;
        int j = 0;
        while(j<nums.size()){
            if(nums[j]==i){
                j++;
            }
            else{
                k--;
            }
            if(k==0){
                return i;
            }
            i++;
        }
        return nums[nums.size()-1]+k;
    }
};