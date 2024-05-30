class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0, r = 0, maxlen = 0, count = 0;
        unordered_map<char,int> m;
        while(r<s.size()){
            if(m.count(s[r])==0){
                count++;
            }
            m[s[r]]++;
            while(count==3){
                maxlen += s.size()-r;
                m[s[l]]--;
                if(m[s[l]]==0){
                    count--;
                    m.erase(s[l]);
                }
                l++;
            }
            r++;
        }
        return maxlen;
    }
};