class Solution {
public:
    int max(int a,int b,int c){
        if(a>=b && a>=c){
            return a;
        } if(b>=a && b>=c){
            return b;
        }
        return c;
    }
    int max(int a,int b){
        if(a>=b){
            return a;
        }
        return b;
    }

    int dfs(vector<vector<int>>& grid,vector<vector<int>> &vis,pair<int,int> p,int parent){
        if(p.first<0 || p.first>=grid.size() || p.second<0 || p.second>=grid[0].size() || grid[p.first][p.second]<=parent){
            return -1;
        }
        if(vis[p.first][p.second]!=-1){
            return vis[p.first][p.second];
        }
        return vis[p.first][p.second] = 1+max(dfs(grid,vis,{p.first-1,p.second+1},grid[p.first][p.second]),dfs(grid,vis,{p.first,p.second+1},grid[p.first][p.second]),dfs(grid,vis,{p.first+1,p.second+1},grid[p.first][p.second]));
    }

    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),-1));
        for(int i=0;i<grid.size();i++){
            ans = max(ans,dfs(grid,vis,{i,0},-1));
        }
        return ans;
    }
};