class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        vector<int> ans(queries.size(), 0);
        map<int, int> m;
        sort(items.begin(), items.end());
        int a = items[0][1];
        int obj = items[0][0];
        for (int i = 1; i < items.size(); i++) {
            if (items[i][0] == obj) {
                a = max(a, items[i][1]);
                continue;
            }
            m[obj] = a;
            obj = items[i][0];
            a = max(a, items[i][1]);
        }
        m[obj] = a;
        for (int i = 0; i < queries.size(); i++) {
            auto it = m.upper_bound(queries[i]);
            if (it != m.begin()) {
                --it;
                ans[i] = it->second;
            }
        }
        return ans;
    }
};