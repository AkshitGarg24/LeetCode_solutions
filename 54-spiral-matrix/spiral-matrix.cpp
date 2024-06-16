class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int l = 0;
        int r = matrix[0].size() - 1;
        int t = 0;
        int b = matrix.size() - 1;
        while (l <= r && t <= b) {
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[t][i]);
            }
            t++;
            if (l > r || t > b) {
                break;
            }
            for (int i = t; i <= b; i++) {
                ans.push_back(matrix[i][r]);
            }
            r--;
            if (l > r || t > b) {
                break;
            }
            for (int i = r; i >= l; i--) {
                ans.push_back(matrix[b][i]);
            }
            b--;
            if (l > r || t > b) {
                break;
            }
            for (int i = b; i >= t; i--) {
                ans.push_back(matrix[i][l]);
            }
            l++;
            if (l > r || t > b) {
                break;
            }
        }
        return ans;
    }
};