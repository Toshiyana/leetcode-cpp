#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/maximum-subarray/discuss/20452/C%2B%2B-DP-and-Divide-and-Conquer

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0, smax = INT_MIN;
        for (int n : nums)
        {
            sum += n;
            cout << "sum: " << sum << endl;
            smax = max(smax, sum);
            cout << "smax: " << smax << endl;
            if (sum < 0)
                sum = 0;

            cout << endl;
        }
        return smax;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << sol.maxSubArray(nums) << endl;
}