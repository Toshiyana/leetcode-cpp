#include <bits/stdc++.h>

using namespace std;

// best approach is app 3.

// approach1: naive programming (fibonacci, recursive)
// TLE
// class Solution
// {
// public:
//     int climbStairs(int n)
//     {
//         if (n == 1)
//             return 1;
//         if (n == 2)
//             return 2;
//         return climbStairs(n - 1) + climbStairs(n - 2);
//     }
// };

// // approach2: Top Down Approach (memo recursive)
// int t[46] = {0}; // constraints: 1 <= n <= 45
// class Solution
// {
// public:
//     int climbStairs(int n)
//     {
//         if (n == 1)
//         {
//             // t[n] = 1; // not necessary
//             return 1;
//         }
//         else if (n == 2)
//         {
//             // t[n] = 2; // not necessary
//             return 2;
//         }
//         else
//         {
//             if (t[n] != 0)
//                 return t[n];
//             else
//             {
//                 t[n] = climbStairs(n - 1) + climbStairs(n - 2);
//                 return t[n];
//             }
//         }
//     }
// };

// approach3: Bottom Up Approach (dynamic programming)
// 再帰を利用せずに、最初から配列を利用。
// 配列に計算結果を格納することで、計算の重複を防げる。
class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> dp(n + 1, 0);

        dp[1] = 1;
        if (n >= 2)
            dp[2] = 2;

        for (int i = 3; i <= n; i++)
            dp[i] = dp[i - 1] + dp[i - 2];

        return dp[n];
    }
};

int main()
{
    Solution sol;
    cout << sol.climbStairs(3) << endl;
}