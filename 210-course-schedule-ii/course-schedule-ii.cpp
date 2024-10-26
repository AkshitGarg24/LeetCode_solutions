class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        queue<int> q;
        for(auto x : prerequisites){
            adj[x[0]].push_back(x[1]);
            vis[x[1]]++;
        }
        for(int i=0;i<vis.size();i++){
            if(vis[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int i = q.front();
            q.pop();
            ans.push_back(i);
            for(auto x : adj[i]){
                vis[x]--;
                if(vis[x]==0){
                    q.push(x);
                }
            }
        }
        reverse(ans.begin(),ans.end());
        if(ans.size()==n){
            return ans;
        }
        return {};
    }
};