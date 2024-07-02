class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int front = nums[0][0];
        int back = nums[0][1];
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i][0]<=back){
                back = max(back,nums[i][1]);
            }
            else{
                ans.push_back({front,back});
                front = nums[i][0];
                back = nums[i][1];
            }
        }
        ans.push_back({front,back});
        return ans;
    }
};