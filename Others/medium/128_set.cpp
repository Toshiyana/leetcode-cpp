#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/longest-consecutive-sequence/discuss/41055/My-really-simple-Java-O(n)-solution-Accepted

// Runtime: 92 ms

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        int res = 0;
        unordered_map<int, int> mp;

        for (int n : nums)
        {
            if (!mp.count(n)) // not include key n in mp
            {
                int left = mp.count(n - 1) ? mp[n - 1] : 0;
                int right = mp.count(n + 1) ? mp[n + 1] : 0;
                // sum: length of the sequence n is in
                int sum = left + right + 1;
                mp[n] = sum;

                // keep track of the max length
                res = max(res, sum);

                // extend the length to the boundary(s)
                // of the sequence
                // will do nothing if n has no neighhbors
                // sequenceの境界（端）にのみ、sum (= length)を入れておけば良い。
                // <- 今後、境界より内側の値にアクセスすることはないから
                mp[n - left] = sum;  // 左端
                mp[n + right] = sum; // 右端
            }
            else
            {
                // duplicates
                continue;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};

    cout << sol.longestConsecutive(nums) << endl;
}