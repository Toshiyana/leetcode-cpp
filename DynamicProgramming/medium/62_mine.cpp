#include <bits/stdc++.h>

using namespace std;

// Error

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        return factorial(m + n - 2) / (factorial(m - 1) * factorial(n - 1));
    }

private:
    double factorial(int x)
    {
        double res = 1;
        for (int i = 1; i <= x; i++)
            res *= i;

        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.uniquePaths(23, 12) << endl;
}