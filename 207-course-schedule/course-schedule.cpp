class Solution {
public:
    bool canFinish(int v, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(v);
	    vector<int> vis(v,0);
	    for(auto x : prerequisites){
	        adj[x[0]].push_back(x[1]);
	        vis[x[1]]++;
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