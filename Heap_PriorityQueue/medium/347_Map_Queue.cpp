#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/top-k-frequent-elements/discuss/81624/C%2B%2B-O(n-log(n-k))-unordered_map-and-priority_queue(maxheap)-solution

// C++ O(n log(n-k)) unordered_map and priority_queue(maxheap) solution
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (int n : nums)
            mp[n]++;

        vector<int> res;
        // pair<first, second>: first is frequency, second is number
        priority_queue<pair<int, int>> pq;

        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            pq.push(make_pair(it->second, it->first));
            if (pq.size() > (int)mp.size() - k)
            {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }

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