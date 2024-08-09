class Solution {
public:
    void func(vector<vector<int>> &ans,vector<int> &x,int idx,int k,int n,int &sum){
        if(x.size()==k){
            if(sum==n){
                ans.push_back(x);
            }
            return;
        }
        if(idx>9){
            return;
        }
        sum += idx;
        x.push_back(idx);
        func(ans,x,idx+1,k,n,sum);
        sum -= idx;
        x.pop_back();
        func(ans,x,idx+1,k,n,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> x;
        int idx = 1;
        int sum = 0;
        func(ans,x,idx,k,n,sum);
        return ans;
    }
};