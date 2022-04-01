#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/discuss/39420/Three-lines-in-C%2B%2B-with-explanation

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i = 0, N = prices.size() - 1;
        int buy, sell, profit = 0;

        while (i < N)
        {
            // cout << "i: " << i << endl;
            while (i < N && prices[i + 1] <= prices[i])
                i++;
            buy = prices[i];
            // cout << "i: " << i << ", buy: " << buy << endl;

            while (i < N && prices[i + 1] > prices[i])
                i++;
            sell = prices[i];
            // cout << "i: " << i << ", sell: " << sell << endl;

            profit += sell - buy;
            // cout << "i: " << i << ", profit: " << profit << endl;
            // cout << endl;
        }

        return profit;
    }
};

int main()
{
    Solution sol;

    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << sol.maxProfit(prices) << endl;
}