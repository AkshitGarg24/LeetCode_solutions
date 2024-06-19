class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        long long int sum = 1;
        for(int i=1;i<=rowIndex;i++){
            sum *= rowIndex+1-i;
            sum /= i;
            ans.push_back(sum);
        }
        return ans;
    }
};