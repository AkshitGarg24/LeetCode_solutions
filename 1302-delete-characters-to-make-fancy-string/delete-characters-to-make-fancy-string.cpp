class Solution {
public:
    string makeFancyString(string s) {
        if(s.size()<3){
            return s;
        }
        string ans = "";
        int i=0;
        for(;i<s.size()-2;i++){
            if(s[i]==s[i+1] && s[i+1]==s[i+2]){
                continue;
            }
            ans += s[i];
        }
        while(i<s.size()){
            ans += s[i];
            i++;
        }
        return ans;
    }
};