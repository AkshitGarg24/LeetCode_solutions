//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int ans = 0;
        int i = 0, j =arr.size()-1;
        while(i<j){
            if(arr[i]+arr[j]<target){
                i++;
            } else if (arr[i]+arr[j]>target){
                j--;
            } else {
                int x = 0, y = 0, ele1 = arr[i], ele2 = arr[j];
                while(i<=j && arr[i]==ele1){
                    x++;
                    i++;
                }
                while(i<=j && arr[j]==ele2){
                    y++;
                    j--;
                }
                if(ele1==ele2){
                    ans += x*(x-1)/2;
                    continue;
                }
                ans += x*y;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends