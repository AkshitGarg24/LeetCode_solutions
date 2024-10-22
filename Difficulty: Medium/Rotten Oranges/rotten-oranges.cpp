//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void checkOrange(vector<vector<int>>& mat,int &ans,queue<pair<int,int>> &q,vector<vector<int>> &vis){
        while(!q.empty()){
            int x = q.size();
            bool check = false;
            while(x--){
                pair<int,int> p = q.front();
                q.pop();
                if(p.first<0 || p.first>=mat.size() || p.second<0 || p.second>=mat[0].size() || mat[p.first][p.second]==0 || vis[p.first][p.second]==1){
                    continue;
                }
                if(mat[p.first][p.second]==1){
                    check = true;
                }
                vis[p.first][p.second] = 1;
                mat[p.first][p.second] = 2;
                q.push({p.first+1,p.second});
                q.push({p.first-1,p.second});
                q.push({p.first,p.second+1});
                q.push({p.first,p.second-1});
            }
            if(check==true){
                ans++;
            }
        }
    }
    
    int orangesRotting(vector<vector<int>>& mat) {
        queue<pair<int,int>> q;
        vector<vector<int>> vis(mat.size(), vector<int> (mat[0].size(),0));
        int ans = 0;
        bool check = false;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    check = true;
                }
                if(mat[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(check==false){
            return 0;
        }
        checkOrange(mat,ans,q,vis);
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(mat);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends