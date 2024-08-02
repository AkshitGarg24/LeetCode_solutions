class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        int n = details.size();
        for(int i=0;i<n;i++){
            string a = "";
            a += details[i][11];
            a += details[i][12];
            int x = stoi(a);
            if(x>60){
                ans++;
            }
        }
        return ans;
    }
};