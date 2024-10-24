//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

    bool dfs(int v,vector<int>adj[],vector<int> &vis,int i){
        for(auto x : adj[i]){
            if(vis[x]==0){
                if(vis[i]==1){
                    vis[x] = 2;
                } else {
                    vis[x] = 1;
                }
                bool m = dfs(v,adj,vis,x);
                if(!m){
                    return false;
                }
            } else if(vis[x]==vis[i]){
                return false;
            }
        }
        return true;
    }

	bool isBipartite(int v, vector<int>adj[]){
	    vector<int> vis(v,0);
	    for(int i=0;i<v;i++){
	        if(vis[i]==0){
	            vis[i] = 1;
	            bool m = dfs(v,adj,vis,i);
	            if(!m){
	                return false;
	            }
	        }
	    }
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends