class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int max = INT_MIN;
        int idx = -1;
        for(int i=0;i<mat.size();i++){
            int ans = 0;
            for(auto a : mat[i]){
                if(a==1){
                    ans++;
                }
            }
            if(ans>max){
                max = ans;
                idx = i;
            }
        }
        return {idx,max};
    }
};