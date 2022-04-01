#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/subsets-ii/discuss/30164/Accepted-10ms-c%2B%2B-solution-use-backtracking-only-10-lines-easy-understand.

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> sub;
        vector<vector<int>> subs;

        subsetsWithDup(nums, 0, sub, subs);

        return subs;
    }

private:
    void subsetsWithDup(vector<int> &nums, int begin, vector<int> &sub, vector<vector<int>> &subs)
    {
        subs.push_back(sub);

        for (int i = begin; i < nums.size(); i++)
        {
            if (i == begin || nums[i] != nums[i - 1])
            {
                sub.push_back(nums[i]);
                subsetsWithDup(nums, i + 1, sub, subs);
                sub.pop_back();
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2};

    print2dVector(sol.subsetsWithDup(nums));
}