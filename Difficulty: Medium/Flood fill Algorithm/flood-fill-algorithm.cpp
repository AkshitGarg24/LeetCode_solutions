//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void check(vector<vector<int>>& image,int sr,int sc, int color,vector<vector<int>> &vis){
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int a = image[sr][sc];
        while(!q.empty()){
            pair<int,int> x = q.front();
            q.pop();
            if(x.first<0 || x.first>=image.size() || x.second<0 || x.second>=image[0].size()){
                continue;
            }
            if(image[x.first][x.second]==a && vis[x.first][x.second]==0){
                vis[x.first][x.second] = 1;
                image[x.first][x.second] = color;
                q.push({x.first+1,x.second});
                q.push({x.first-1,x.second});
                q.push({x.first,x.second+1});
                q.push({x.first,x.second-1});
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        vector<vector<int>> vis(image.size(),vector<int> (image[0].size(),0));
        check(image,sr,sc,newColor,vis);
        return image;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends