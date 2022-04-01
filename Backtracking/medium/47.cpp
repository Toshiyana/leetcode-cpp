#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/permutations-ii/discuss/18596/A-simple-C%2B%2B-solution-in-only-20-lines

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        permuteRecursive(nums, 0, res);

        return res;
    }

private:
    void permuteRecursive(vector<int> &nums, int begin, vector<vector<int>> &res)
    {
        int n = nums.size();

        if (begin == n)
            res.push_back(nums);
        else
        {
            for (int i = begin; i < n; ++i)
            {
                if (i > begin && nums[i] == nums[begin])
                    continue;
                swap(nums[begin], nums[i]);
                permuteRecursive(nums, begin + 1, res);
            }

            // Restore nums
            for (int i = n - 1; i > begin; --i)
                swap(nums[begin], nums[i]);
        }
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 2};

    print2dVector(sol.permuteUnique(nums));
}