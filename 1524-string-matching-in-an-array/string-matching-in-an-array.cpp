class Solution {
public:
    static bool cmp(string &a,string &b){
        return a.size()>b.size();
    }
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        vector<string> ans;
        for(int i=1;i<words.size();i++){
            int j = i-1;
            while(j>=0){
                string x = words[i], y = words[j];
                size_t idx = y.find(x);
                if(idx!=string::npos){
                    ans.push_back(x);
                    break;
                }
                j--;
            }
        }
        return ans;
    }
};