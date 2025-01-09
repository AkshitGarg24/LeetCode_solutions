class Solution {
public:
    int prefixCount(vector<string>& words, string s) {
        int ans = 0;
        for(int i=0;i<words.size();i++){
            string x = words[i];
            int j = 0, k = 0;
            bool check = true;
            while(j<s.size() && k<x.size()){
                if(s[j]==x[k]){
                    j++;k++;
                } else {
                    check = false;
                    break;
                }
            }
            if(j<s.size() && k==x.size()){
                check = false;
            }
            if(check){
                ans++;
            }

        }
        return ans;
    }
};