#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/house-robber/discuss/1605797/C%2B%2BPython-4-Simple-Solutions-w-Explanation-or-Optimization-from-Brute-Force-to-DP

class Solution
{
public:
    // pattern3: DP
    int rob(vector<int> &nums)
    {
        vector<int> dp(nums); // dp[i]: i番目の中からi個選択した時の総和の最大値（初期値はnumsの値）

        if (size(nums) == 1)
            return nums[0];

        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < size(nums); i++)
        {
            dp[i] = max(dp[i - 1], dp[i] + dp[i - 2]);
        }

        return dp.back(); // 最後の要素を返す
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 7, 9, 3, 1};
    vector<int> dp(nums);

    print1dVector(nums);
}