class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini = INT_MAX-10;
        int mini2 = INT_MAX;
        int maxi = INT_MIN+10;
        int maxi2 = INT_MIN;
        int idxmin = - 1;
        int idxmax = -1;
        for(int i=0;i<arrays.size();i++){
            if(arrays[i][arrays[i].size()-1]>maxi){
                maxi2 = maxi;
                maxi = arrays[i][arrays[i].size()-1];
                idxmax = i;
            } else if (maxi>=arrays[i][arrays[i].size()-1] && maxi2<arrays[i][arrays[i].size()-1]){
                maxi2 = arrays[i][arrays[i].size()-1];
            }
            if(arrays[i][0]<mini){
                mini2 = mini;
                mini = arrays[i][0];
                idxmin = i;
            } else if(mini<=arrays[i][0] && mini2>arrays[i][0]){
                mini2 = arrays[i][0];
            }
        }
        if(idxmin!=idxmax){
            return maxi-mini;
        }
        return max(maxi2-mini,maxi-mini2);
    }
};