class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<target.size();i++){
            m[target[i]]++;
            m[arr[i]]--;
        }
        for(auto x : m){
            if(x.second!=0){
                return false;
            }
        }
        return true;
    }
};