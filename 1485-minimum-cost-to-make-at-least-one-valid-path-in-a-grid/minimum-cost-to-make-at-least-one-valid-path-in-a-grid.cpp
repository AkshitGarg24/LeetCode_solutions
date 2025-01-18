class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> x = {0, 0, 0, 1, -1}; // Movement directions
        vector<int> y = {0, 1, -1, 0, 0}; // (right, left, down, up)

        deque<pair<int, int>> dq; // Deque for BFS
        vector<vector<int>> cost(m, vector<int>(n, INT_MAX)); // Cost array
        cost[0][0] = 0;
        dq.push_front({0, 0}); // Start from top-left corner

        while (!dq.empty()) {
            auto [i, j] = dq.front();
            dq.pop_front();

            for (int k = 1; k <= 4; ++k) {
                int a = i + x[k];
                int b = j + y[k];
                if (a >= 0 && a < m && b >= 0 && b < n) {
                    int newCost = cost[i][j] + (k == grid[i][j] ? 0 : 1);
                    if (newCost < cost[a][b]) {
                        cost[a][b] = newCost;
                        if (k == grid[i][j]) {
                            dq.push_front({a, b}); // Push to the front for no extra cost
                        } else {
                            dq.push_back({a, b}); // Push to the back for extra cost
                        }
                    }
                }
            }
        }

        return cost[m - 1][n - 1]; // Return cost to bottom-right corner
    }
};
