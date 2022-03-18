#include <bits/stdc++.h>

using namespace std;

// DP
// pattern1: Sum Max
// https://algo-method.com/tasks/307/editorial

// Input
int N;
int A[10010]; // 最大10000個だが、少しだけ多めにとる

// DP table
int dp[10010];

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    dp[0] = 0;
    for (int i = 0; i < N; i++)
    {
        dp[i + 1] = max(dp[i] + A[i], dp[i]); // max(選ぶ, 選ばない)
    }

    cout << dp[N] << endl;
}