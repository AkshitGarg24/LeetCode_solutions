class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        unordered_map<char,int> b;
        for(int i=0;i<words2.size();i++){
            unordered_map<char,int> a;
            for(auto &x : words2[i]){
                a[x]++;
            }
            for(auto &x : a){
                if(b.find(x.first)==b.end()){
                    b[x.first] = a[x.first];
                } else {
                    b[x.first] = max(b[x.first],a[x.first]);
                }
            }
        }

        for(int i=0;i<words1.size();i++){
            bool check = true;
            unordered_map<char,int> m;
            for(auto &x : words1[i]){
                m[x]++;
            }
            for(auto &x : b){
                if(m.find(x.first)==m.end() || m[x.first]<b[x.first]){
                    check = false;
                    break;
                }
            }
            if(check){
                ans.push_back(words1[i]);
            }
            
        }
        return ans;
    }
};