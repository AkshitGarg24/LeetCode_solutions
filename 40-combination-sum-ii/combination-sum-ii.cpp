class Solution {
public:
    void func(vector<int> &candidates,int target,int &sum,vector<vector<int>> &ans,vector<int> &x,int idx){
        if(sum>target){
            return;
        }
        if(sum==target || idx==candidates.size()){
            if(sum==target){
                ans.push_back(x);
                return;
            }
        }
        while(idx<candidates.size()){
            sum += candidates[idx];
            x.push_back(candidates[idx]);
            func(candidates,target,sum,ans,x,idx+1);
            sum -= candidates[idx];
            x.pop_back();
            int i = idx;
            while(i<candidates.size() && candidates[idx]==candidates[i]){
                i++;
            }
            if(i>=candidates.size()){
                return;
            }
            idx = i;
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> x;
        func(candidates,target,sum,ans,x,0);
        return ans;
    }
};