class Solution {
public:
    int maxProfit(vector<int>& nums) {
        vector<int> x(2,0); 
        vector<int> y(2,0);
        vector<int> temp(2);
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=1;j>=0;j--){
                int a = 0, b = 0;
                if(j==0){
                    b  = -nums[i];
                    if(i+1<nums.size()){
                        a = x[j], b += x[1];
                    }
                } else {
                    b = nums[i];
                    if(i+1<nums.size()){
                        a = x[j];
                    }
                    if(i+2<nums.size()){
                        b += y[0];
                    }
                }
                temp[j] = max(a,b);
            }
            y = x;
            x = temp;
        }
        return x[0];
    }
};