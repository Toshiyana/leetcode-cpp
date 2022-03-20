#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[110];

bool dp[110][10010];
// dp[i+1][j]: i番目までの整数の中からいくつか選んで、総和がjになるか

int main()
{
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // 初期条件
    memset(dp, 0, sizeof(dp)); // 一旦全てfalse
    dp[0][0] = true;           // 0個の整数の和は0

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= M; j++)
        {
            dp[i + 1][j] |= dp[i][j];
            if (j >= A[i])
                dp[i + 1][j] |= dp[i][j - A[i]];
        }
    }

    if (dp[N][M])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}