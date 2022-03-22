#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> nums1, vector<int> nums2)
    {
        unordered_set<int> s(nums1.begin(), nums1.end()); // set(集合)は重複要素を追加しても、自動的に削除される。
        vector<int> res;

        for (auto n : nums2)
        {
            if (s.count(n))
            {
                res.push_back(n);
                s.erase(n);
            }
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    sol.intersection(nums1, nums2);
}