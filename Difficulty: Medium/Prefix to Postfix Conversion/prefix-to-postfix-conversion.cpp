//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string s) {
        stack<string> st;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='-' || s[i]=='+' || s[i]=='*' || s[i]=='/' || s[i]=='^' || s[i]=='%'){
                string a = st.top(); st.pop();
                string b = st.top(); st.pop();
                string ans = a + b + s[i];
                st.push(ans);
            } else {
                string x(1,s[i]);
                st.push(x);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends