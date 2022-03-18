#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/maximum-subarray/discuss/1595195/C%2B%2BPython-7-Simple-Solutions-w-Explanation-or-Brute-Force-%2B-DP-%2B-Kadane-%2B-Divide-and-Conquer

// Recursive (TLE)

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return solve(nums, 0, false);
    }

private:
    int solve(vector<int> &nums, int i, bool mustPick)
    {
        // our subarray must contain at least 1 element.
        // If mustPick is false at end means no element is picked and this is not valid case.
        if (i >= size(nums))
            return mustPick ? 0 : -1e5;
        if (mustPick)
            return max(0, nums[i] + solve(nums, i + 1, true));                     // either stop here or choose current element and recurse
        return max(solve(nums, i + 1, false), nums[i] + solve(nums, i + 1, true)); // try both choosing current element or not choosing
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << sol.maxSubArray(nums) << endl;
}