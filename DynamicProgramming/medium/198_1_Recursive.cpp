#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/house-robber/discuss/1605797/C%2B%2BPython-4-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP

class Solution
{
public:
    // pattern1: Recursive (TLE)
    int rob(vector<int> &nums)
    {
        return rob(nums, 0);
    }

    int rob(vector<int> &nums, int i)
    {
        return i < size(nums) ? max(rob(nums, i + 1), nums[i] + rob(nums, i + 2)) : 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    vector<int> dp(nums);

    print1dVector(nums);
}