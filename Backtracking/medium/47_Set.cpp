#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/permutations-ii/discuss/18632/Short-40ms-C%2B%2B-solution-similar-to-Permutation-I-solution
// This is like the Permutation (46.cpp), but we use an unordered_set to avoid swapping elements that are the same (which would generate identical permutations).

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> res;

        permuteRecursive(nums, 0, res);

        return res;
    }

private:
    void permuteRecursive(vector<int> &nums, int begin, vector<vector<int>> &res)
    {
        if (begin == nums.size())
        {
            res.push_back(nums);
            return;
        }

        unordered_set<int> st;

        for (int i = begin; i < nums.size(); i++)
        {
            if (st.count(nums[i]) == 1)
                continue;
            st.insert(nums[i]);
            swap(nums[begin], nums[i]);
            permuteRecursive(nums, begin + 1, res);
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