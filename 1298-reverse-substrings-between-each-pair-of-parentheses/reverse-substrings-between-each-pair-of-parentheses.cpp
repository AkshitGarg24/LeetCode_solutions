class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        int i = 0;
        while(i<s.size()){
            
            if(s[i]==')'){
                int x = st.top();
                st.pop();
                reverse(s.begin()+x,s.begin()+i+1);
                s.erase(s.begin()+i);
                s.erase(s.begin()+x);
                i--;
            }
            else if(s[i]=='('){
                st.push(i);
                i++;
            }
            else{
                i++;
            }
        }

        return s;

        // string ans = "";
        // for(auto x : s){
        //     if(x!='(' && x!=')'){
        //         ans += x;
        //     }
        // }
        // return ans;
    }
};