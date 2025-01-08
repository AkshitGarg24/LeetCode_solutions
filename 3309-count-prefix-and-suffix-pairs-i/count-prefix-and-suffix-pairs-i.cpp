class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                string a = words[i], b = words[j];
                if(a.size()>b.size()){
                    continue;
                }
                int i = 0,m = a.size()-1, y = b.size()-1;
                bool check1 = true, check2 = true;
                while(i<a.size()){
                    if(a[i]!=b[i]){
                        check1 = false;
                        break;
                    }
                    i++;
                }
                while(m>=0){
                    if(a[m]!=b[y]){
                        check2 = false;
                        break;
                    }
                    m--;
                    y--;
                }
                if(check1 && check2){
                    ans++;
                }
            }
        }
        return ans;
    }
};