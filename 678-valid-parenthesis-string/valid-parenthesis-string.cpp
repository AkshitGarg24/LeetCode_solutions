class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                min++;
                max++;
            } else if (s[i]==')') {
                min--;
                max--;
            } else {
                min--;
                max++;
            }
            if(max<0){
                return false;
            }
            if(min<0){
                min = 0;
            } 
        }
        return min==0;
    }
};