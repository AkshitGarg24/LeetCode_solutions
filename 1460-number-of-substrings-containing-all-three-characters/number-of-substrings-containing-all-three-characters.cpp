class Solution {
public:
    int min(int &a,int &b,int &c){
        if(a<=b && a<=c) return a;
        if(b<=a && b<=c) return b;
        return c;
    }
    int numberOfSubstrings(string s) {
        int ans = 0;
        vector<int> lastseen(3,-1);
        for(int i=0;i<s.size();i++){
            lastseen[s[i]-'a'] = i;
            ans += min(lastseen[0],lastseen[1],lastseen[2]) + 1;
        }
        return ans;
    }
};