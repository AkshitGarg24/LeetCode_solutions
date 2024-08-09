class Solution {
public:
    void func(vector<vector<int>> &ans,vector<int>& nums,vector<int> &x,int idx,vector<int> &a){
        if(idx>=nums.size()){
            ans.push_back(x);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(a[i]==-1){
                x.push_back(nums[i]);
                a[i] = 1;
                func(ans,nums,x,idx+1,a);
                x.pop_back();
                a[i] = -1;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a(nums.size(),-1);
        vector<int> x;
        func(ans,nums,x,0,a);
        return ans;
    }
};