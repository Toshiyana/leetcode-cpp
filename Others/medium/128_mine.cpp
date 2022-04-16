#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// Runtime: 38 ms

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int len = 1, ans = 1;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[i - 1];
            // diff == 0で同じ値が連続する時は、lenはそのまま。
            if (diff == 1)
            {
                len++;
                ans = max(ans, len);
            }
            else if (diff > 1)
                len = 1;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
}