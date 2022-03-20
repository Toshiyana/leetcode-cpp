#include <bits/stdc++.h>

using namespace std;

// combinations count
// https://leetcode.com/problems/unique-paths/discuss/1581998/C%2B%2BPython-5-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP-to-Math

// Time Complexity : O(min(m,n))
// Space Complexity : O(1)

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        long res = 1;
        for (int i = m + n - 2, j = 1; i >= max(m, n); i--, j++)
            res = (res * i) / j;

        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.uniquePaths(23, 12) << endl;
}