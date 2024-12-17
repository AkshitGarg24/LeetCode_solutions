//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int prec(char x){
        if(x=='^'){
            return 4;
        }
        if(x=='*' || x=='/'){
            return 3;
        } else if(x=='+' || x=='-') {
            return 2;
        } else {
            return 1;
        }
    }
    string infixToPostfix(string& s) {
        stack<char> st;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || s[i]=='^' || s[i]=='(' || s[i]==')'){
                if(s[i]==')'){
                    while(st.top()!='('){
                        ans += st.top();
                        st.pop();
                    }
                    st.pop();
                    continue;
                }
                else if(s[i]=='('){
                    st.push(s[i]);
                }
                else{
                    while(!st.empty() && prec(st.top())>=prec(s[i])){
                        ans += st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
                
            } else {
                ans += s[i];
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
//  Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends