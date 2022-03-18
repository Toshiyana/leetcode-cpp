#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int N = size(nums);
        vector<vector<int>> dp(2, vector<int>(N));
        dp[0][0] = dp[1][0] = nums[0];
        for (int i = 1; i < N; i++)
        {
            // dp[1][i] denotes maximum subarray sum ending at i (including nums[i])
            dp[1][i] = max(nums[i], nums[i] + dp[1][i - 1]);
            // dp[0][i] denotes maximum subarray sum upto i (may or may not include nums[i])
            dp[0][i] = max(dp[0][i - 1], dp[1][i]);
        }
        return dp[0].back();
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << sol.maxSubArray(nums) << endl;
}