class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& x) {
        int i = 0;
        int n = intervals.size();
        vector<vector<int>> ans;
        while(i<n && intervals[i][1]<x[0]){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i< n && intervals[i][0]<=x[1]){
            x[0] = min(x[0],intervals[i][0]);
            x[1] = max(x[1],intervals[i][1]);
            i++;
        }
        ans.push_back(x);
        while(i<n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};