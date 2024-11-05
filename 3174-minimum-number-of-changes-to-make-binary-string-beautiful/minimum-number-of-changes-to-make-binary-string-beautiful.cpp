class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        char x = s[0];
        int cnt = 0;
        for(int i=0;i<s.size();i++){
            if(x==s[i]){
                cnt++;
            } else {
                if(cnt&1!=0){
                    ans++;
                    if(i+1<s.size()){
                        x = s[i+1];
                        cnt = 0;
                    }
                } else {
                    x = s[i];
                    cnt = 1;
                }
            }
        }
        return ans;
    }
};