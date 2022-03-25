#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        vector<int> res;

        for (int n : nums)
            mp[n]++;

        // printUnorderedMap(mp);

        int maxNum, maxKey;
        for (int i = 0; i < k; i++)
        {
            maxNum = 0;
            for (auto it = mp.begin(); it != mp.end(); ++it)
            {
                if (it->second > maxNum)
                {
                    maxKey = it->first;
                    maxNum = it->second;
                }
            }
            res.push_back(maxKey);
            mp.erase(maxKey);
        }

        // print1dVector(res);

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;

    sol.topKFrequent(nums, k);
}