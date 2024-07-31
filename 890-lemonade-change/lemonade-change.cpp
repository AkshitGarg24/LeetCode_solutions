class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            } else if(bills[i]==10){
                if(five<=0){
                    cout<<i;
                    cout<<10;
                    return false;
                }
                five--;
                ten++;
            }  else if(bills[i]==20){
                if(five>0 && ten>0){
                    five--;
                    ten--;
                    continue;
                } else if(five-3>=0){
                    five -= 3;
                    continue;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};