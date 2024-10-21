class Solution {
public:
    int check(string s, int l, unordered_set<string>& a) {
        int ans = 0;
        for (int i = l; i < s.size(); i++) {
            string x = s.substr(l, i - l + 1);
            if (a.find(x) == a.end()) {
                a.insert(x);
                ans = max(ans, 1 + check(s, i + 1, a));
                a.erase(x); 
            }
        }
        return ans;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> a;
        return check(s, 0, a);
    }
};
