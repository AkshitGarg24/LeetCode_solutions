class Solution {
public:
    void func(vector<int>& nums,vector<vector<int>> &ans,vector<int> &x,int idx){
        if(idx>=nums.size()){
            ans.push_back(x);
            return;
        }
        x.push_back(nums[idx]);
        func(nums,ans,x,idx+1);
        x.pop_back();
        int i = idx+1;
        while(i<nums.size() && nums[i]==nums[idx]){
            i++;
        }
        if(i==nums.size()){
            ans.push_back(x);
            return;
        }
        func(nums,ans,x,i);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> x;
        func(nums,ans,x,0);
        return ans;
    }
};