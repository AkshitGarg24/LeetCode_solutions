class Solution {
public:
    vector<int> vowelStrings(vector<string>& words,
                             vector<vector<int>>& queries) {
        vector<int> m(words.size() + 1, 0);
        int x = 0;
        for (int i = 1; i < words.size()+1; i++) {
            if ((words[i-1][0] == 'a' || words[i-1][0] == 'e' ||
                 words[i-1][0] == 'i' || words[i-1][0] == 'o' ||
                 words[i-1][0] == 'u') &&
                (words[i-1][words[i-1].size() - 1] == 'a' ||
                 words[i-1][words[i-1].size() - 1] == 'e' ||
                 words[i-1][words[i-1].size() - 1] == 'i' ||
                 words[i-1][words[i-1].size() - 1] == 'o' ||
                 words[i-1][words[i-1].size() - 1] == 'u')) {
                x++;
            }
            m[i] = x;
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            ans[i] = m[queries[i][1]+1]-m[queries[i][0]];
        }
        return ans;
    }
};