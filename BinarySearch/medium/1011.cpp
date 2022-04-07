#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/discuss/256729/JavaC%2B%2BPython-Binary-Search

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int D)
    {
        int left = 0, right = 0;
        for (int w : weights)
        {
            left = max(left, w);
            right += w;
        }

        while (left < right)
        {
            int mid = (left + right) / 2, need = 1, cur = 0;
            for (int w : weights)
            {
                if (cur + w > mid)
                {
                    need++;
                    cur = 0;
                }
                cur += w;
            }
            if (need > D)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};

int main()
{
    Solution sol;
}