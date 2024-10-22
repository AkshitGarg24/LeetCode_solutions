class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        unordered_map<int,int> m;
        int cnt = 0;
        int l = 0, h = 0;
        while(h<s.size()){
            if(m.find(s[h])==m.end()){
                cnt++;
            }
            m[s[h]]++;
            while(cnt==3){
                ans += s.size()-h;
                m[s[l]]--;
                if(m[s[l]]==0){
                    cnt--;
                    m.erase(s[l]);
                }
                l++;
            }
            h++;
        }
        return ans;
    }
};