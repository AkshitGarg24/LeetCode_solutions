class Solution {
public:
    void func(vector<string> &ans,string &x,vector<string> &num,string digits,int idx){
        if(idx>=digits.size()){
            if(x==""){
                return;
            }
            ans.push_back(x);
            return;
        }
        int a = digits[idx]-'0';
        for(int i=0;i<num[a].size();i++){
            x.push_back(num[a][i]);
            func(ans,x,num,digits,idx+1);
            x.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string x = "";
        vector<string> num = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        func(ans,x,num,digits,0);
        return ans;
    }
};