class Solution {
public:
    void func(vector<int> &candidates,int target,int &sum,vector<int> &x,int idx,vector<vector<int>> &ans){
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
        func(candidates,target,sum,x,idx+1,ans);
        x.pop_back();
        sum -= candidates[idx];
        int i = idx+1;
        while(i<candidates.size() && candidates[i]==candidates[idx]){
            i++;
        }
        if(i==candidates.size()){
            return;
        }
        func(candidates,target,sum,x,i,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> x;
        func(candidates,target,sum,x,0,ans);
        return ans;
    }
};