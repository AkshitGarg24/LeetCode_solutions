class Solution {
public:
    int maxProfit(vector<int>& nums) {
        vector<int> temp(2);
        int a = 0;   
        int b = nums[nums.size()-1];  
        for(int i=nums.size()-2;i>=0;i--){
            for(int j=1;j>=0;j--){
                if(j==0){
                    temp[j] = max(a,b-nums[i]);
                } else {
                    temp[j] = max(b,nums[i] + a);
                }
            }
            a = temp[0];
            b = temp[1];
        }
        return a;
    }
};