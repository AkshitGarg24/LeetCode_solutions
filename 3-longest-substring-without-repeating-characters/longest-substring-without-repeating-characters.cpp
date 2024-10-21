class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int l = 0, h = 0;
        unordered_map<char,int> x;
        while(h<s.size()){
            if(x.find(s[h])!=x.end() && x[s[h]]>=l){
                l = x[s[h]]+1;
            }
            ans = max(ans,h-l+1);
            x[s[h]] = h;
            h++;
        }
        return ans;
    }
};