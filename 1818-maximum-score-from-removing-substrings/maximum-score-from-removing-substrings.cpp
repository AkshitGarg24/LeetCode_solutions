class Solution {
public:
    int maximumGain(string s, int x, int y) {
        vector<char> st;
        vector<int> ans;
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0;i<s.size();i++){
            if(st.size()>=1 && s[i]=='b' && st.back()=='a'){
                sum1 += x;
                st.pop_back();
            }
            else{
                st.push_back(s[i]);
            }
        }
        for(int i=0;i<st.size();i++){
            if(ans.size()>=1 && st[i]=='a' && ans.back()=='b'){
                sum1 += y;
                ans.pop_back();
            }
            else{
                ans.push_back(st[i]);
            }
        }
        st.clear();
        ans.clear();
        for(int i = 0;i<s.size();i++){
            if(st.size()>=1 && s[i]=='a' && st.back()=='b'){
                sum2 += y;
                st.pop_back();
            }
            else{
                st.push_back(s[i]);
            }
        }
        for(int i=0;i<st.size();i++){
            if(ans.size()>=1 && st[i]=='b' && ans.back()=='a'){
                sum2 += x;
                ans.pop_back();
            }
            else{
                ans.push_back(st[i]);
            }
        }
        return max(sum1,sum2);
    }
};