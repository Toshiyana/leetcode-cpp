#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/maximum-subarray/discuss/20452/C%2B%2B-DP-and-Divide-and-Conquer

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return maxSubArray(nums, 0, nums.size() - 1);
    }

private:
    int maxSubArray(vector<int> &nums, int l, int r)
    {
        if (l > r)
            return INT_MIN;
        int mid = l + (r - l) / 2, ml = 0, mr = 0;
        int lmax = maxSubArray(nums, l, mid - 1);
        int rmax = maxSubArray(nums, mid + 1, r);

        for (int i = mid - 1, sum = 0; i >= l; i--)
        {
            sum += nums[i];
            ml = max(sum, ml);
        }
        for (int i = mid + 1, sum = 0; i <= r; i++)
        {
            sum += nums[i];
            mr = max(sum, mr);
        }

        return max(max(lmax, rmax), ml + mr + nums[mid]);
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << sol.maxSubArray(nums) << endl;
}