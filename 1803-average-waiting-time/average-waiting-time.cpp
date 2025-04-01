class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans = 0;
        int end = customers[0][1] + customers[0][0];
        ans += customers[0][1];
        for(int i=1;i<customers.size();i++){
            ans += customers[i][1];
            if(end>=customers[i][0]){
                ans += end-customers[i][0];
            }
            end = max(end,customers[i][0]) + customers[i][1];
        }
        ans /= customers.size();
        return ans;
    }
};