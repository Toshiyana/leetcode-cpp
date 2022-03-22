#include <bits/stdc++.h>

using namespace std;

// 63_DP.cppは、冗長な部分がある。
// 以下冗長部分：
// path[i][j]を更新するたびに、path[i - 1][j] (同じ列) と path[i][j - 1] (左の列) が必要なだけなので、m*n の行列をすべて維持する必要がないことです。2列を維持すれば十分である。
// ループを早く終了させることができる場合もある。obstacleGrid = [[0, 1, 0, 0], [0, 1, 0, 0], [0, 1, 0, 0]] とすると、2列目の要素に到達するための経路の数は0なので、2列目を更新しても右下隅に到達できないことが分かる。
// これらを考慮し、以下の最適化されたコードを書き下す。

// 解説
// https://leetcode.com/problems/unique-paths-ii/discuss/23252/4ms-O(n)-DP-Solution-in-C%2B%2B-with-Explanations
// https://procon.fun/2020/04/05/leetcode-63/

// Time Complexity : O(M*N)
// Space Complexity : O(M*N)

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 0);

        dp[0] = 1;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else if (j > 0)
                    dp[j] += dp[j - 1];
            }
        }

        return dp[n - 1];
    }
};

int main()
{
    Solution sol;
}