class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        if(arr.size()==0 || arr.size()==1){
            return arr.size();
        }
        unordered_set<int> s;
        for(int i=0;i<arr.size();i++){
            s.insert(arr[i]);
        }
        int ans = INT_MIN;
        for(auto x : s){
            if(s.find(x-1)==s.end()){
                int cnt = 1;
                while(s.find(x+1)!=s.end()){
                    x++;
                    cnt++;
                }
                ans = max(ans,cnt);
            }
        }
        return ans;
    }
};