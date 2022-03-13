#include <bits/stdc++.h>

using namespace std;

void print1dVector(vector<int> vec)
{
    int length = vec.size();

    cout << "{ ";
    for (int i = 0; i < length; i++)
    {
        cout << vec[i];
        if (i == (length - 1))
            cout << " ";
        else
            cout << ", ";
    }
    cout << "}" << endl;
}

// https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)

// Solution 1: Dynamic Programming
// This is a classic Dynamic Programming problem.
// Let dp[i] is the longest increase subsequence which ends at nums[i].

// Complexity
// Time: O(N^2), where N <= 2500 is the number of elements in array nums.
// Space: O(N)

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);

        for (int i = 0; i < n; i++)
        {
            // cout << "i: " << i << endl;
            for (int j = 0; j < i; j++)
            {
                // cout << "j: " << j << endl;
                if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
                // print1dVector(dp);
            }
            // cout << endl;
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 0, 8, 4, 6};
    cout << sol.lengthOfLIS(nums) << endl;
    // print1dVector(dp);
}