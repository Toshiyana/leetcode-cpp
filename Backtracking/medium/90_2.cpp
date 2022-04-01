#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/subsets-ii/discuss/30168/C%2B%2B-solution-and-explanation

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subs = {{}};
        int start;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i == 0 || nums[i] != nums[i - 1])
                start = 0;
            for (int end = subs.size(); start < end; start++)
            {
                vector<int> clone = subs[start];
                clone.push_back(nums[i]);
                subs.push_back(clone);
            }
        }
        return subs;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2};

    print2dVector(sol.subsetsWithDup(nums));
}