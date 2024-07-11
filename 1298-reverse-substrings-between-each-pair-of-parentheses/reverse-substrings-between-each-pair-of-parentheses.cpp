class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                int x = st.top();
                st.pop();
                reverse(s.begin()+x,s.begin()+i+1);
            }
        }
        string ans = "";
        for(auto x : s){
            if(x!='(' && x!=')'){
                ans += x;
            }
        }
        return ans;
    }
};