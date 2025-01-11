class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.size()){
            return false;
        }
        if(k==s.size()){
            return true;
        }
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        int even = 0,odd = 0;
        for(auto &x : m){
            if(x.second%2==0){
                even++;
            } else {
                odd++;
            }
        }
        return odd<=k;
    }
};