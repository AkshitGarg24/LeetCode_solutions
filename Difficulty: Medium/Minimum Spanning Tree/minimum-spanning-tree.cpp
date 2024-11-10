//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	
	int findParent(vector<int> &parent,int i){
	    if(parent[i]==i){
	        return i;
	    }
	    return parent[i] = findParent(parent,parent[i]);
	}
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans = 0;
        vector<int> rank(V,0);
        vector<int> parent(V);
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0;i<V;i++){
            for(auto x : adj[i]){
                pq.push({x[1],x[0],i});
            }
        }
        
        while(!pq.empty()){
            int a = findParent(parent,pq.top()[1]);
            int b = findParent(parent,pq.top()[2]);
            int wt = pq.top()[0];
            pq.pop();
            if(a==b){
                continue;
            }
            ans += wt;
            if(rank[a]>rank[b]){
                parent[b] = a;
            }
            else if(rank[a]<rank[b]){
                parent[a] = b;
            }
            else {
                parent[a] = b;
                rank[a]++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends