#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // pattern1: clear
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n < 0)
            return 1 / x * myPow(1 / x, -(n + 1));

        return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
    }

    // pattern2
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1;
        if (n == INT_MIN) // avoid integer overflow
        {
            x = x * x;
            n = n / 2;
        }
        if (n < 0)
        {
            n = -n;
            x = 1 / x;
        }

        return (n % 2 == 0) ? myPow(x * x, n / 2) : x * myPow(x * x, n / 2);
    }
};

int main()
{
    Solution sol;
    cout << sol.myPow(2, 4) << endl;
}