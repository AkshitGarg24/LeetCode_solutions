class Solution {
public:
    
    int numEnclaves(vector<vector<int>>& mat) {
        int m = mat[0].size();
        int n = mat.size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && mat[i][j]==1 && vis[i][j]==0){
                    q.push({i,j});
                    vis[i][j] = 1;
                }
            }
        }
        vector<int> w = {1,-1,0,0};
        vector<int> z = {0,0,1,-1};
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int o=0;o<4;o++){
                int a = p.first+w[o];
                int b = p.second+z[o];
                if(a>=0 && a<mat.size() && b>=0 && b<mat[0].size() && vis[a][b]==0 && mat[a][b]==1){
                    q.push({a,b});
                    vis[a][b] = 1;
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==1 && vis[i][j]==0){
                    ans++;
                }
            }
        }
        return ans;
    }
};