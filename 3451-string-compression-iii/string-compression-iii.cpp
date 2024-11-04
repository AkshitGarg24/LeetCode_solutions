class Solution {
public:
    string compressedString(string word) {
        string ans = "";
        char a  = word[0];
        int cnt = 1;
        for(int i=1;i<word.size();i++){
            if(word[i]==a){
                if(cnt==9){
                    ans += to_string(cnt);
                    ans += a;
                    cnt = 0;
                }
                cnt++;
            } else {
                ans += to_string(cnt);
                ans += a;
                cnt = 1;
                a = word[i];
            }
        }
        ans += to_string(cnt);
        ans += a;
        return ans;
    }
};