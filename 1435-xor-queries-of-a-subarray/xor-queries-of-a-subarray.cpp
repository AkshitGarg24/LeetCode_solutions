class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        int x = 0;
        for(int i=0;i<arr.size();i++){
            x ^= arr[i];
            arr[i] = x;
        }
        for(int i=0;i<queries.size();i++){
            x = 0;
            if(queries[i][0]-1>=0){
                x = arr[queries[i][0]-1];
            }
            ans.push_back(arr[queries[i][1]]^x);
        }
        return ans;
    }
};