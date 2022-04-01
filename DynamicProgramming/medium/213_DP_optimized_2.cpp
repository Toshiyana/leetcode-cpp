#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/house-robber-ii/discuss/59986/C%2B%2B-Super-Simple-0ms-solution-with-explanation

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        // Since you cannot rob both the first and last house, just create two separate vectors
        vector<int> numsA(nums.begin(), nums.end() - 1);
        vector<int> numsB(nums.begin() + 1, nums.end());

        return max(robOriginal(numsA), robOriginal(numsB));
    }

    int robOriginal(vector<int> &nums)
    {
        int cur = 0, prev = 0, prev2 = 0;
        for (int n : nums)
        {
            cur = max(prev, prev2 + n);
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