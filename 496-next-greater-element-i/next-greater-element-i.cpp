class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans(nums2.size(),-1);
        stack<int> s;
        for(int i=0;i<nums2.size();i++){
            while(!s.empty() && nums2[i]>nums2[s.top()]){
                ans[s.top()] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
        vector<int> x(nums1.size());
        unordered_map<int,int> m;
        for(int i=0;i<nums2.size();i++){
            m[nums2[i]] = i;
        }
        for(int i=0;i<nums1.size();i++){
            x[i] = ans[m[nums1[i]]];
        }
        return x;
    }
};