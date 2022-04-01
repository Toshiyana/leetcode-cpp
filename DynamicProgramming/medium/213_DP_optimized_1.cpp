#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/house-robber-ii/discuss/59921/9-lines-0ms-O(1)-Space-C%2B%2B-solution

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();

        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
    }

    int robber(vector<int> &nums, int l, int r)
    {
        int cur = 0, prev = 0, prev2 = 0;
        for (int i = l; i <= r; i++)
        {
            cur = max(prev, prev2 + nums[i]);
            prev2 = prev;
            prev = cur;
        }
        return cur;
    }
};

int main()
{
    Solution sol;
}