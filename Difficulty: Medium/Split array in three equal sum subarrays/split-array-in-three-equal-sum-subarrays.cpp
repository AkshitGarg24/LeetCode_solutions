//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  Class Solution to contain the method for solving the problem.
class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
        }
        if(sum%3!=0){
            return {-1,-1};
        }
        int i = 1;
        int x = sum/3;
        int a = arr[0];
        while(a<x){
            a += arr[i];
            i++;
        }
        if(a>x){
            return {-1,-1};
        }
        a = arr[i];
        int j = i+1;
        i--;
        
        while(a<x){
            a += arr[j];
            j++;
        }
        if(a>x){
            return {-1,-1};
        }
        j--;
        return {i,j};
    }
};

//{ Driver Code Starts.

int main() {
    int test_cases;
    cin >> test_cases;
    cin.ignore();
    while (test_cases--) {
        string input;
        vector<int> arr;

        // Read the array from input line
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        // Solution instance to invoke the function
        Solution ob;
        vector<int> result = ob.findSplit(arr);

        // Output result
        if (result[0] == -1 && result[1] == -1) {
            cout << "false" << endl;
        } else {
            cout << "true" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends