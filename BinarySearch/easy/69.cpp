#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        long long start = 0, end = x, ans, mid;
        while (start <= end)
        {
            mid = (start + end) / 2;
            if (mid * mid == x)
                return mid;
            else if (mid * mid < x)
            {
                start = mid + 1;
                ans = mid; // 'ans' is maintained to keep track of only lowest 'mid' value,
                // because the dicimal part is truncated.
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.mySqrt(4) << endl;
}