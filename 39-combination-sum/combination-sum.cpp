class Solution {
public:
    void func(vector<vector<int>> &ans, vector<int> &candidates, int target, int idx,int &sum,vector<int> &x){
        if(sum>target){
            return;
        }
        if(sum==target || idx>=candidates.size()){
            if(sum==target){
                ans.push_back(x);
            }
            return;
        }
        x.push_back(candidates[idx]);
        sum += candidates[idx];
        func(ans,candidates,target,idx,sum,x);
        x.pop_back();
        sum -= candidates[idx];
        func(ans,candidates,target,idx+1,sum,x);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> x;
        func(ans,candidates,target,0,sum,x);
        return ans;
    }
};