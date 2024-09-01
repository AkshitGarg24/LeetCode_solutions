class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n!=original.size()){
            return {};
        }
        vector<vector<int>> ans;
        int x = 0;
        for(int i=0;i<m;i++){
            vector<int> a;
            for(int j=0;j<n;j++){
                a.push_back(original[x]);
                x++;
            }
            ans.push_back(a);
        }
        return ans;
    }
};