class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;
        unordered_map<char,pair<int,int>> m;
        for(int i=0;i<s.size();i++){
            if(m.find(s[i])!=m.end()){
                m[s[i]].second = i;
            } else {
                m[s[i]] = {i,-1};
            }
        }
        for (auto& x : m) {
            int start = x.second.first;
            int end = x.second.second;
            if (start < end) {
                unordered_set<char> q(s.begin() + start + 1, s.begin() + end);
                ans += q.size();
            }
        }

        return ans;
    }
};