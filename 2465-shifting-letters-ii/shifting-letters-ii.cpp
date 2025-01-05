class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> temp(s.size()+1,0);
        int q;
        for(auto x : shifts){
            if(x[2]==1){
                temp[x[0]]++;
                temp[x[1]+1]--; 
            } else {
                temp[x[0]]--;
                temp[x[1]+1]++;
            }
        }
        int b = 0;
        for(int i=0;i<temp.size();i++){
            temp[i] += b;
            b = temp[i];
            int a = (int)(s[i]) + temp[i]%26;
            if(a<97){
                a = a+26;
            } else if (a>122){
                a = a-26;
            }
            s[i] = char(a);
        }
        return s;
    }
};