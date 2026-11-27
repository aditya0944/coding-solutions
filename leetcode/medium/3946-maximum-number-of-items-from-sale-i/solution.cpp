class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> frees(n, 0);
        for (int i = 0; i < n; ++i) {
            int fi = items[i][0];
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % fi == 0) {
                    ++cnt;
                }
            }
            frees[i] = cnt;
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; ++i) {
            int price = items[i][1];
            int gain = 1 + frees[i];
            for (int b = budget; b >= price; --b) {
                dp[b] = max(dp[b], dp[b - price] + gain);
            }
        }

        for (int b = 1; b <= budget; ++b) {
            for (int i = 0; i < n; ++i) {
                int price = items[i][1];
                if (b >= price) {
                    dp[b] = max(dp[b], dp[b - price] + 1);
                }
            }
        }

        return dp[budget];
    }
};
