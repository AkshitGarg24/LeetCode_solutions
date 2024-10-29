class Solution {
public:

    void bfs(vector<vector<int>> &adj,int i,vector<int> &vis){
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(vis[x]){
                continue;
            }
            vis[x] = 1;
            for(auto m : adj[x]){
                if(!vis[m]){
                    q.push(m);
                }
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& x) {
        if(x.size()<n-1){
            return -1;
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<x.size();i++){
            adj[x[i][0]].push_back(x[i][1]);
            adj[x[i][1]].push_back(x[i][0]);
        }
        int ans = 0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ans++;
                bfs(adj,i,vis);
            }
        }
        return ans-1;
    }
};