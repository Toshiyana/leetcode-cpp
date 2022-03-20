#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> subs;
        vector<int> sub;

        subsets(nums, 0, subs, sub);

        return subs;
    }

private:
    void subsets(vector<int> &nums, int i, vector<vector<int>> &subs, vector<int> &sub)
    {
        subs.push_back(sub);

        for (int j = i; j < nums.size(); j++)
        {
            sub.push_back(nums[j]);
            subsets(nums, j + 1, subs, sub);
            sub.pop_back(); // 末尾要素の削除（backtrack）
        }
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};

    print2dVector(sol.subsets(nums));
}