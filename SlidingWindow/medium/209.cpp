#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/minimum-size-subarray-sum/discuss/59090/C%2B%2B-O(n)-and-O(nlogn)

// Time Complexity : O(n)

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int l = 0, r = 0, n = nums.size(), sum = 0, len = INT_MAX;

        while (r < n)
        {
            sum += nums[r++];
            // cout << "r: " << r << ", sum+: " << sum << endl;
            while (sum >= target)
            {
                len = min(len, r - l);
                sum -= nums[l++];

                // cout << "len_min: " << len << endl;
                // cout << "l: " << l << ", sum-: " << sum << endl;
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};

int main()
{
    Solution sol;
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};

    cout << sol.minSubArrayLen(target, nums) << endl;
}