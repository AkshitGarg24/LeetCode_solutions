//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int v,int p, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> adj(v);
	    vector<int> vis(v,0);
	    for(auto x : prerequisites){
	        adj[x.first].push_back(x.second);
	        vis[x.second]++;
	    }
	    queue<int> q;
	    int size = 0;
	    for(int i=0;i<vis.size();i++){
	        if(vis[i]==0){
	            q.push(i);
	        }
	    }
	    while(!q.empty()){
	        int i = q.front();
	        q.pop();
	        size++;
	        for(auto x : adj[i]){
	            vis[x]--;
	            if(vis[x]==0){
	                q.push(x);
	            }
	        }
	    }
	    return (size==v);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends