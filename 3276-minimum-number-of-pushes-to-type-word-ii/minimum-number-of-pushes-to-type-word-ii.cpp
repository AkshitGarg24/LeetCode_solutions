class Solution {
public:
    static bool cmp(pair<char,int> &a,pair<char,int> &b){
        return a.second>b.second;
    }
    int minimumPushes(string word) {
        int ans = 0;
        unordered_map<char,int> m;
        for(int i=0;i<word.size();i++){
            m[word[i]]++;
        }
        if(m.size()<=8){
            for(auto it : m){
                ans += it.second;
            }
            return ans;
        }
        vector<pair<char,int>> v;
        for(auto it : m){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
        int count = 8;
        for(int i=0;i<v.size();i++){
            ans += (v[i].second)*(count/8);
            count++;
        }
        return ans;
    }
};