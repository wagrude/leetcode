class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> ans(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            int minCost = INT_MAX;

            for(int j = max(0, i - 3); j < i; j++) {
                minCost = min(minCost, ans[j] + (i - j) * (i - j) + costs[i - 1]);
            }

            ans[i] = minCost;
        }

        return ans[n];
    }
};