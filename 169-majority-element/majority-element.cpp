class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int i = 0;
        int count  = 0;
        int element = nums[i];
        while(i<nums.size()){
            if(nums[i]==element){
                count++;
            } else {
                count--;
            }
            if(count==0){
                element = nums[i+1];
            }
            i++;
        }
        return element;
    }
};