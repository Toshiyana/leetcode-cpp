#include <bits/stdc++.h>

using namespace std;

// 集合
// http://vivi.dyndns.org/tech/cpp/set.html#:~:text=%E3%81%BE%E3%81%A8%E3%82%81%E3%83%BB%E5%8F%82%E8%80%83-,C%2B%2B%20%E9%A0%86%E5%BA%8F%E4%BB%98%E9%9B%86%E5%90%88%20std%3A%3Aset%20%E3%81%A8%E3%81%AF,%E3%81%AE%E3%82%88%E3%81%86%E3%81%AA%E3%82%82%E3%81%AE%E3%81%A0%E3%80%82

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