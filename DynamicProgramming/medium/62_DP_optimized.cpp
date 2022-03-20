#include <bits/stdc++.h>

using namespace std;

// DP - tabulation
// https://leetcode.com/problems/unique-paths/discuss/1581998/C%2B%2BPython-5-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Math

// Time Complexity : O(m*n), for computing dp values for each of the m*n cells.
// Space Complexity : O(n), required to maintain dp. We are only keeping two rows of length n giving space complexity of O(n).

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[j] += dp[j - 1];

        return dp[n - 1];
    }
};

int main()
{
    Solution sol;
    cout << sol.uniquePaths(23, 12) << endl;
}