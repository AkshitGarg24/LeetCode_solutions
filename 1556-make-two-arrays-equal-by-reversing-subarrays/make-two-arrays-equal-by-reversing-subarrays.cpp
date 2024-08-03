class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<target.size();i++){
            m[target[i]]++;
            if(m[target[i]]==0){
                m.erase(target[i]);
            }
            m[arr[i]]--;
            if(m[arr[i]]==0){
                m.erase(arr[i]);
            }
        }
        return m.empty();
    }
};