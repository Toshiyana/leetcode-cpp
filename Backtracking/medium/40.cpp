#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/combination-sum-ii/discuss/16862/C%2B%2B-backtracking-solution-with-detailed-explanation

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum2(candidates, target, res, combination, 0);
        return res;
    }

private:
    void combinationSum2(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &combination, int begin)
    {
        if (target == 0)
        {
            res.push_back(combination);
            return;
        }

        for (int i = begin; i < candidates.size() && candidates[i] <= target; i++)
        {
            if (i > begin && candidates[i] == candidates[i - 1]) // check duplicate combination
                continue;
            combination.push_back(candidates[i]);
            combinationSum2(candidates, target - candidates[i], res, combination, i + 1);
            combination.pop_back();
        }
    }
};

int main()
{
    Solution sol;
}