class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        vector<vector<int>> m(arr.size()+1);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                m[mat[i][j]] = {i,j};
            }
        }
        vector<int> x(mat[0].size()),y(mat.size());
        for(int i=0;i<arr.size();i++){
            auto q = m[arr[i]];
            x[q[1]]++;
            y[q[0]]++;
            if(x[q[1]]>=mat.size() || y[q[0]]>=mat[0].size()){
                return i;
            }
        }
        return -1;
    }
};