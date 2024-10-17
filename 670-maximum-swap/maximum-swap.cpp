class Solution {
public:
    static bool cmp(pair<char,int> &a,pair<char,int> &b){
        return a.first>b.first;
    }
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<pair<char,int>> pq;
        for(int i=0;i<s.size();i++){
            pq.push_back({s[i],i});
        }
        sort(pq.begin(),pq.end(),cmp);
        for(int i=0;i<pq.size();i++){
            char a = pq[i].first;
            int b = pq[i].second;
            if(s[i]==a){
                continue;
            } else {
                for(int j=i;j<s.size();j++){
                    if(pq[j].first==a){
                        b = max(b,pq[j].second);
                    }
                }
                swap(s[i],s[b]);
                break;
            }
        }
        int m = stoi(s);
        return m;
    }
};