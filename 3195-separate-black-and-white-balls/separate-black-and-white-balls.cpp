class Solution {
public:
    long long minimumSteps(string s) {
        long long int ans = 0;
        int j = s.size()-1;
        while(j>=0 && s[j]=='1'){
            j--;
        }
        if(j<0){
            return ans;
        }
        int i = j;
        while(i>=0){
            if(s[i]=='1'){
                ans += j-i;
                j--;
            }
            i--;
        }
        return ans;
    }
};