class Solution {
public:
    vector<int> x = {+1,-1,0,0};
    vector<int> y = {0,0,+1,-1};
    vector<vector<int>> highestPeak(vector<vector<int>>& nums) {
        vector<vector<int>> ans(nums.size(),vector<int> (nums[0].size()));
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(nums.size(),vector<int> (nums[0].size(),0));
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums[0].size();j++){
                if(nums[i][j]){
                    vis[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        } 
        while(!q.empty()){
            auto m = q.front();
            int i = m.first.first, j = m.first.second, val = m.second;
            q.pop();
                ans[i][j] = val;
                for(int k=0;k<4;k++){
                    int a = i+x[k];
                    int b = j + y[k];
                    if(a>=0 && a<nums.size() && b>=0 && b<nums[0].size() && !vis[a][b]){
                        vis[a][b] = 1;
                        q.push({{a,b},val+1});
                    }
                }
            
        }
        return ans;
    }
};