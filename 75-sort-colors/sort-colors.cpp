class Solution {
public:
    void sortColors(vector<int>& nums) {
       int l = -1, r = nums.size();
       for(int i=0;i<nums.size() && i<r;i++){
        if(nums[i]==0){
            while(l<i && nums[i]==0){
                swap(nums[++l],nums[i]);
            }
            while (i<r && nums[i]==2){
                swap(nums[--r], nums[i]);
            }
        }
        if (nums[i]==2){
            while (i<r && nums[i]==2){
                swap(nums[--r], nums[i]);
            }
            while(l<i && nums[i]==0){
                swap(nums[++l],nums[i]);
            }
        }
        
       } 
    }
};