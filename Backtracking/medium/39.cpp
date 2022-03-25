#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/combination-sum/discuss/16496/Accepted-16ms-c%2B%2B-solution-use-backtracking-easy-understand.

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        return res;
    }

private:
    void combinationSum(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &combination, int begin)
    {
        // cout << "comb: ";
        // print1dVector(combination);

        // cout << "res: ";
        // print2dVector(res);

        if (!target) // if target (= target - candidates[i]) is 0
        {
            res.push_back(combination);
            return;
        }

        for (int i = begin; i < candidates.size() && candidates[i] <= target; ++i)
        {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};

int main()
{
    Solution sol;
    // vector<int> candidates = {2, 3, 6, 7};
    // int target = 7;

    vector<int> candidates = {2, 3, 5};
    int target = 8;

    vector<vector<int>> result = sol.combinationSum(candidates, target);
    // print2dVector(result);
}