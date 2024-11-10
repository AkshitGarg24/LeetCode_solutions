//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    static bool cmp(pair<int,int> &a,pair<int,int> &b){
        double x = (double)a.first/a.second;
        double y = (double)b.first/b.second;
        return x>y;
    }
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        double ans = 0;
        vector<pair<int,int>> v;
        for(int i=0;i<val.size();i++){
            v.push_back({val[i],wt[i]});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0;i<v.size();i++){
            double c = min(capacity,v[i].second);
            ans += c*v[i].first/v[i].second;
            capacity -= c;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends