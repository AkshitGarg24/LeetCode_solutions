class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        int idx1 = -1,idx2 = -1;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i]){
                cnt++;
                if(cnt>2){
                    return false;
                }
                if(cnt==1){
                    idx1 = i;
                } else if(cnt==2){
                    idx2 = i;
                }
            }
        }
        if(cnt==1){
            return false;
        }
        if(cnt==0){
            return true;
        }
        swap(s2[idx1],s2[idx2]);
        return s1==s2;
    }
};