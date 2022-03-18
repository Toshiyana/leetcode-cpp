#include <bits/stdc++.h>

using namespace std;

// https://algo-method.com/tasks/308/editorial

// dp[i+1][j] : i番目までの品物の中から重さjを超えないように選んだ時の価値の総和の最大値

// Input
int N, W;
int w[110], v[110];

// DP table
int dp[110][1010]; // dp[i+1][w]の漸化式を考える

int main()
{
    cin >> N >> W;
    for (int i = 0; i < N; i++)
        cin >> w[i] >> v[i];

    // DP 初期化条件
    for (int j = 0; j < W; j++)
        dp[0][j] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (w[i] <= j)
            {
                // 重さ(j)の価値の総和の最大値 =
                // 重さ(j-w[i])の価値の総和の最大値 + 重さ(w[i])で価値(v[i])
                dp[i + 1][j] = max(dp[i][j - w[i]] + v[i], dp[i][j]);
            }
            else
                dp[i + 1][j] = dp[i][j];
        }
    }

    cout << dp[N][W] << endl;
}