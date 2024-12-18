//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job {
    int id;       // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};


// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int deadline; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution {
  public:
    // Function to find the maximum profit and the number of jobs done.
    
    static bool cmp(Job j1, Job j2){
        return j1.profit>j2.profit;
    }
    
    vector<int> JobScheduling(Job jobs[], int n) {
        sort(jobs,jobs+n,cmp);
        int count = 0,prof = 0;
        vector<int> x(n+1,-1);
        for(int i=0;i<n;i++){
            int m = jobs[i].deadline;
            while(m>0 && x[m]!=-1){
                m--;
            }
            if(m>0){
                count++;
                prof += jobs[i].profit;
                x[m] = jobs[i].id;
            }
        }
        return {count,prof};
    }
};

//{ Driver Code Starts.
//    Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;

    while (t--) {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].deadline = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends