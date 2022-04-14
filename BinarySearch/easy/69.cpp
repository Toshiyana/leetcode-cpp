#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/sqrtx/discuss/553452/C%2B%2B-Binary-Search-Approach-Runtime%3A-0ms-Faster-than-100

// Time Complexity: O(logn) | due to binary search using while loop.
// Space Complexity: O(1) | as only 4 variables are initialized at the beginning. Which is constant irrespective of given input.

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