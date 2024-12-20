class Solution {
public:
    int maxProfit(vector<int>& nums) {
        vector<int> x(2,0); 
        vector<int> y(2,0);
        vector<int> temp(2);
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                if(j==0){
                    temp[j] = max(x[j],-nums[i] + x[1]);
                } else {
                    temp[j] = max(x[j],nums[i] + y[0]);
                }
            }
            y = x;
            x = temp;
        }
        return x[0];
    }
};