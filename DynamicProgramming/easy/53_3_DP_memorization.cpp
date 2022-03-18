#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<vector<int>> dp(2, vector<int>(size(nums), -1));
        cout << -1e5 << endl;
        return solve(nums, 0, false, dp);
    }

private:
    int solve(vector<int> &nums, int i, bool mustPick, vector<vector<int>> &dp)
    {
        if (i >= size(nums))
            return mustPick ? 0 : -1e5;
        if (dp[mustPick][i] != -1)
            return dp[mustPick][i];
        if (mustPick)
        {
            dp[mustPick][i] = max(0, nums[i] + solve(nums, i + 1, true, dp));
            return dp[mustPick][i];
        }
        dp[mustPick][i] = max(solve(nums, i + 1, false, dp), nums[i] + solve(nums, i + 1, true, dp));
        return dp[mustPick][i];
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << sol.maxSubArray(nums) << endl;
}