#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/house-robber/discuss/1605797/C%2B%2BPython-4-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP

class Solution
{
public:
    // pattern4: Space-Optimized DP
    int rob(vector<int> &nums)
    {
        int cur = 0, prev = 0, prev2 = 0;
        for (int i : nums)
        {
            cur = max(prev, i + prev2);
            prev2 = prev;
            prev = cur;
        }
        return cur;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    vector<int> dp(nums);

    print1dVector(nums);
}