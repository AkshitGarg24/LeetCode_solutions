class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x = 0,y = 0, a = num1, b = num2,idx = -1;
        while(a>0){
            if(a&1){
                x++;
            }
            a >>= 1;
            idx++;
        }
        while(b>0){
            if(b&1){
                y++;
            }
            b >>= 1;
        }
        if(x==y){
            return num1;
        } else if (x>y){
            int i = 0,ans = 0;
            while(y){
                if(num1&(1<<idx)){
                    ans |= (1<<idx);
                    y--;
                }
                idx--;
            }
            return ans;
        } else {
            int i = 0,ans = 0;
            while(y-x){
                if(num1&(1<<i)){
                    ans |= 1<<i;
                    i++;
                    y--;x--;
                    continue;
                }
                ans |= 1<<i;
                i++;
                y--;
            }
            while(x){
                if(num1&(1<<i)){
                    ans |= 1<<i;
                    x--;
                } 
                i++;
            }
            return ans;
        }
        return -1;
    }
};