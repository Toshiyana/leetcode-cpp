#include <bits/stdc++.h>

using namespace std;

// 境界条件、dpのサイズをm,nでなくm+1,n+1にする理由がよくわかっていない。

// 解説
// https://leetcode.com/problems/unique-paths-ii/discuss/23252/4ms-O(n)-DP-Solution-in-C%2B%2B-with-Explanations
// https://procon.fun/2020/04/05/leetcode-63/

// Time Complexity : O(M*N)
// Space Complexity : O(N)

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // dp[0][0] is dummy.

        // 境界条件
        dp[0][1] = 1; // or dp[1][0] = 1 でも良い。ループ内でdp[1][1]=1になる (= 開始セルgrid[0][0]に到達する方法が一つあることを意味する)。

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (!obstacleGrid[i - 1][j - 1]) // when the obstacle doesn't exist
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

        return dp[m][n];
    }
};

int main()
{
    Solution sol;
}