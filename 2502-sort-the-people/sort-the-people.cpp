class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> m;
        for(int i=0;i<names.size();i++){
            m.insert({heights[i],names[i]});
        }
        vector<string> ans;
        for(auto itr=m.begin();itr != m.end();itr++){
            ans.insert(ans.begin(),itr->second);
        }
        return ans;
    }
};