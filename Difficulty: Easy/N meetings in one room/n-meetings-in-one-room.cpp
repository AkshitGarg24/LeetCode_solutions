//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

struct meeting{
    int start;
    int end;
    int position;
};

class Solution
{
    public:
    //Function to fsind the maximum number of meetings that can
    //be performed in a meeting room.
    static bool cmp(meeting a, meeting b){
        return a.end<b.end;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<meeting> x(n);
        for(int i=0;i<n;i++){
            x[i].start = start[i];
            x[i].end = end[i];
            x[i].position = i+1;
        }
        int ans = 0;
        int freeTime = -1;
        sort(x.begin(),x.end(),cmp);
        for(int i=0;i<n;i++){
            if(x[i].start>freeTime){
                ans++;
                freeTime = x[i].end;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends