class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1;
        int x = nums[0];
        int j = 0;
        for(int i=1;i<nums.size();i++){
            if(x!=nums[i]){
                count++;
                x = nums[i];
                nums[++j] = x;
            }
        }
        return count;
    }
};