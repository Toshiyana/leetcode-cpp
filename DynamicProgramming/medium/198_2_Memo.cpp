#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/house-robber/discuss/1605797/C%2B%2BPython-4-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP

class Solution
{
public:
    // pattern2: Recursice-Memorization
    int rob(vector<int> &nums)
    {
        vector<int> memo(size(nums), -1); // initial values are -1 (= not still calculated)
        return rob(nums, memo, 0);
    }

    int rob(vector<int> &nums, vector<int> &memo, int i)
    {
        if (i >= size(nums))
            return 0;
        if (memo[i] != -1) // already calculated
            return memo[i];

        // initial "i" is 0, so we use i+1, i+2, not i-1, i-2
        return memo[i] = max(rob(nums, memo, i + 1), nums[i] + rob(nums, memo, i + 2)); // if not calculated
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    vector<int> dp(nums);

    print1dVector(nums);
}