#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/maximum-subarray/discuss/1595195/C%2B%2BPython-7-Simple-Solutions-w-Explanation-or-Brute-Force-%2B-DP-%2B-Kadane-%2B-Divide-and-Conquer

// brute-force (TLE)

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int curSum = 0;
            for (int j = i; j < n; j++)
            {
                curSum += nums[j];
                ans = max(ans, curSum);
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << sol.maxSubArray(nums) << endl;
}