#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minPrice = INT_MAX;
        int maxPro = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            minPrice = min(minPrice, prices[i]);
            maxPro = max(maxPro, prices[i] - minPrice);

            // cout << "i: " << i << endl;
            // cout << "minPrice: " << minPrice << endl;
            // cout << "maxProfit: " << maxPro << endl;
            // cout << endl;
        }
        return maxPro;
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << sol.maxProfit(prices) << endl;
}