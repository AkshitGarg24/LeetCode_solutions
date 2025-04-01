class Solution {
public:
bool dfs(vector<int> &color, int v, vector<vector<int>> &adj){
        if(color[v]!=-1){
            return true;
        }
        bool zero = false, one = false;
        for(auto x : adj[v]){
            if(color[x]==0){
                zero = true;
            }
            if(color[x]==1){
                one = true;
            }
            if(zero && one){
                return false;
            }
        }
        if(zero){
            color[v] = 1;
        } else {
            color[v] = 0;
        }
        bool ans = true;
        for(auto x : adj[v]){
            if(color[x]==-1){
                ans &= dfs(color, x, adj);
                if(ans==false){
                    return ans;
                }
            }
        }
        return ans;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        vector<int> usedColors(adj.size(),-1);
        bool ans = true;
        for(int i=0;i<adj.size();i++){
            if(usedColors[i]==-1){
                ans &= dfs(usedColors, i, adj);
            }
        }
        return ans;
    }
};