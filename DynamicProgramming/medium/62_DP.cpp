#include <bits/stdc++.h>

using namespace std;

// DP - tabulation
// https://leetcode.com/problems/unique-paths/discuss/1581998/C%2B%2BPython-5-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Math

// Time Complexity : O(m*n), we are computing dp values for each of the m*n cells from the previous cells value. Thus, the total number of iterations performed is requires a time of O(m*n).
// Space Complexity : O(m*n), required to maintain the dp matrix

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // 条件
        // 0 <= i <= m-1
        // 0 <= j <= n-1

        // 初期条件
        // * dp[0][0] = 1
        // * dp[i][0] = 1 and dp[0][j] = 1

        // (i, j) に対して、上の (i-1, j) または左の (i, j-1) からここに到達可能。
        // つまり、(i, j)に到達するためのユニークなパスの数の結果は、両方の合計、すなわち、dp[i][j] = dp[i-1][j] + dp[i][j-1] になります。

        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m - 1][n - 1];
    }
};

int main()
{
    Solution sol;
    cout << sol.uniquePaths(2, 3) << endl;
}