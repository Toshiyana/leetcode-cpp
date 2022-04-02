#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84551/simple-Java-O(KlogK)-solution-with-explanation/640135

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;

        if (nums1.size() == 0 || nums2.size() == 0 || k == 0)
            return ans;

        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        for (int i = 0; i < min((int)nums1.size(), k); i++)
            pq.push({nums1[i], nums2[0], 0});

        while (k-- > 0 && !pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            ans.push_back({top[0], top[1]});

            if (top[2] + 1 < nums2.size())
                pq.push({top[0], nums2[top[2] + 1], top[2] + 1});
        }

        return ans;
    }

private:
    struct Compare
    {
        bool operator()(vector<int> &t1, vector<int> &t2)
        {
            return ((t1[0] + t1[1]) > (t2[0] + t2[1]));
        }
    };
};

int main()
{
    Solution sol;
}