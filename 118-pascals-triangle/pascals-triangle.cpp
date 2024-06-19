class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; i++) {
            vector<int> x;
            long long int sum = 1;
            x.push_back(1);
            for (int j = 1; j <= i; j++) {
                sum *= i + 1 - j;
                sum /= j;
                x.push_back(sum);
            }
            ans.push_back(x);
        }
        return ans;
    }
};