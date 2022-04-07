#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/coin-change/discuss/77360/C%2B%2B-O(n*amount)-time-O(amount)-space-DP-solution
// https://leetcode.com/problems/coin-change/discuss/77360/C++-O(n*amount)-time-O(amount)-space-DP-solution/81414

class Solution
{
public:
    // Iterating over all combinations instead of all permutations (better than Sol1)
    int coinChange(vector<int> &coins, int amount)
    {
        // dp[i]: 総和iとなるときのコインの総数の最小値
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int coin : coins)
        {
            for (int i = coin; i <= amount; i++)
                dp[i] = min(dp[i], dp[i - coin] + 1);
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

class Solution2
{
public:
    // Iterating over all permutations
    int coinChange(vector<int> &coins, int amount)
    {
        // dp[i]: 総和iとなるときのコインの総数の最小値
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (int j = 0; j < coins.size(); j++)
            {
                if (coins[j] <= i)
                {
                    // cout << "i: " << i << endl;
                    // cout << "j: " << j << ", coins[j]: " << coins[j] << endl;
                    // cout << "dp[" << i << "]: " << dp[i] << endl;
                    // cout << "dp[" << i << "-" << coins[j] << "]: " << dp[i - coins[j]] << endl;

                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);

                    // cout << "min_dp[" << i << "]: " << dp[i] << endl;
                    // cout << endl;
                }
            }
            // cout << endl;
            // cout << endl;
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main()
{
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << sol.coinChange(coins, amount) << endl;
}