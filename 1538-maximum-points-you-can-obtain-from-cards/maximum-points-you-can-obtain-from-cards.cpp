class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int l = cards.size()-k;
        int h = cards.size()-1;
        int sum = 0;
        for(int i=l;i<=h;i++){
            sum += cards[i];
        }
        if(k==cards.size()){
            return sum;
        }
        int ans = sum;
        h++;
        while((h%cards.size())<k){
            sum -= cards[l];
            l++;
            sum += cards[h%cards.size()];
            ans = max(ans,sum);
            h++;
        }
        return ans;
    }
};