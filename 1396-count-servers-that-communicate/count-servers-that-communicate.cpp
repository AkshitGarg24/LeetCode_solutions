class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<bool>> temp(grid.size(),vector<bool> (grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            int cnt = 0,idx;
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]){
                    cnt++;
                    idx = j;
                    temp[i][j] = true;
                }
            }
            if(cnt==1){
                temp[i][idx] = false;
            } else {
                ans += cnt;
            }
        }
        for(int i=0;i<grid[0].size();i++){
            int cnt = 0,notpicked = 0;
            for(int j=0;j<grid.size();j++){
                if(grid[j][i]){
                    cnt++;
                    if(!temp[j][i]){
                        notpicked++;
                    }
                }
            }
            if(cnt>1){
                ans += notpicked;
            }
        }
        return ans;
    }
};