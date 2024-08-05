class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(m[arr[i]]==1){
                k--;
            }
            if(k==0){
                return arr[i];
            }
        }
        
        return "";
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();