#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int curMax = 0, maxTilNow = INT_MIN;
        for (int n : nums)
        {
            curMax = max(n, curMax + n);
            maxTilNow = max(maxTilNow, curMax);
        }
        return maxTilNow;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << sol.maxSubArray(nums) << endl;
}