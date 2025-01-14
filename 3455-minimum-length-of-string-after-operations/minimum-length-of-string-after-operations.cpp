class Solution {
public:
    int minimumLength(string s) {
        vector<int> temp(26,0);
        for(int i=0;i<s.size();i++){
            if(temp[s[i]-'a']==0){
                temp[s[i]-'a'] = 1;
            } else if (temp[s[i]-'a']==1){
                temp[s[i]-'a'] = -1;
            } else if (temp[s[i]-'a']==-1){
                temp[s[i]-'a'] = 1;
            }
        }
        int ans = 0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==1){
                ans++;
            } else if (temp[i]==-1){
                ans += 2;
            }
        }
        return ans;
    }
};