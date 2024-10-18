//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        char x = str[str.size()-1];
        if(x<='5'){
            str[str.size()-1] = '0';
        } else {
            str[str.size()-1] = '0';
            int i = str.size()-2;
            while(i>=0 && str[i]=='9'){
                str[i] = '0';
                i--;
            }
            if(i>=0){
                str[i]++;
            } else {
                str = '1' + str;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends