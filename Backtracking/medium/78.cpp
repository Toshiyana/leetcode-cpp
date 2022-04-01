#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>> subs;
        vector<int> sub;

        subsets(nums, 0, subs, sub);

        return subs;
    }

private:
    void subsets(vector<int> &nums, int begin, vector<vector<int>> &subs, vector<int> &sub)
    {
        subs.push_back(sub);

        for (int i = begin; i < nums.size(); i++)
        {
            sub.push_back(nums[i]);
            subsets(nums, i + 1, subs, sub);
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