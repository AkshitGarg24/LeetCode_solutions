class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int x = 0;
        while(x<nums.size()){
            int i = x+1;
            int j = nums.size()-1;
            while(i<nums.size() && i<j){
                if(nums[i]+nums[j]==(-nums[x])){
                    ans.push_back({nums[x],nums[i],nums[j]});
                    int a = nums[i];
                    int b = nums[j];
                    while(i<nums.size() && nums[i]==a){
                        i++;
                    }
                    while(j>x && nums[j]==b){
                        j--;
                    }
                }
                else if(nums[i]+nums[j]<(-nums[x])){
                    i++;
                }
                else{
                    j--;
                }
            }
            int c = nums[x];
            while(x<nums.size() && nums[x]==c){
                x++;
            }
        }
        return ans;
    }
};