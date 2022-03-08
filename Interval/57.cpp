#include <bits/stdc++.h>
#include "./../Utils/Utils.h"

#define Interval vector<int>

using namespace std;

class Solution
{
public:
    // algorithm
    // 1. put all intervals that are to the left of the inserted interval
    // 2. merge all intervals that intersect with the inserted interval
    // 3. put all intervals that are to the right of the inserted interval
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
        vector<Interval> res;
        int i = 0;

        // Left part (no intersection with newInterval)
        while (i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            res.push_back(intervals[i]);
            i++;
        }

        // newIterval part (with or without merge)
        while (i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            ++i;
        }
        res.push_back(newInterval);

        // Right part (no intersection with new Interval)
        while (i < intervals.size() && intervals[i][0] > newInterval[1])
        {
            res.push_back(intervals[i]);
            ++i;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<Interval> result;

    // Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
    // Output: [[1,5],[6,9]]

    // vector<vector<int>> intervals = {{1, 3}, {6, 9}, {2, 4}};
    // vector<int> newInterval = {2, 5};

    vector<vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval = {4, 9};

    // cout << intervals[0][0] << endl;
    // cout << intervals[1][1] << endl;
    // cout << intervals[0].front() << endl;
    // cout << intervals[1].back() << endl;

    result = sol.insert(intervals, newInterval);
    print2dVector(result);
}