class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> ans(A.size());
        unordered_set<int> s;
        int x = 0;
        for(int i=0;i<A.size();i++){
            if(s.find(A[i])==s.end()){
                s.insert(A[i]);
            } else {
                x++;
            }

            if(s.find(B[i])==s.end()){
                s.insert(B[i]);
            } else {
                x++;
            }

            ans[i] = x;
        }
        return ans;
    }
};