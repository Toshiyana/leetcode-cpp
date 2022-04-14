#include <bits/stdc++.h>
using namespace std;

int N, L, K, A[100010];

// 001_1.cppはめぐる式二分探索で、001_2は通常の二分探索（違うの37, 38行目だけ）

// 「最大何個の長さM以上のピースに分割できるか」という判定問題 <= 最小値の最大化
bool solve(int M)
{
    int cnt = 0, pre = 0;
    for (int i = 1; i <= N; i++)
    {
        if (A[i] - pre >= M && L - A[i] >= M)
        {
            cnt++;
            pre = A[i];
        }
    }
    if (cnt >= K)
        return true;
    else
        return false;
}

int main()
{
    // n: 切れ目の数、l: ようかんの長さ、k: n個の切れ目のうち、k個選び、k+1個に分割 (k <= n)
    // a[i]: 左からi番目の切れ目の位置[cm]
    cin >> N >> L;
    cin >> K;
    for (int i = 1; i <= N; i++)
        cin >> A[i];

    // Step #2. 答えで二分探索（めぐる式二分探索法）
    // https://qiita.com/drken/items/97e37dd6143e33a64c8c
    int left = 0; // 違うのここだけ
    int right = L;
    while (right - left > 1)
    {
        int mid = left + (right - left) / 2;
        if (!solve(mid))
            right = mid;
        else
            left = mid;
    }
    cout << left << endl;
}