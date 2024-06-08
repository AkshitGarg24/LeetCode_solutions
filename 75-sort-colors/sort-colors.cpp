class Solution {
public:
    void sortColors(vector<int>& nums) {
        int x = 0;
        int y = nums.size()-1;
        for(int i=0;i<=y;i++){
            while(nums[i]==2 && y>=0 && y>=i){
                swap(nums[i],nums[y--]);
            }
            if(nums[i]==0 && x<nums.size()){
                swap(nums[i],nums[x++]);
            }
        }
    }
};