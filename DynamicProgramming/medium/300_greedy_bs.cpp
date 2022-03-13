#include <bits/stdc++.h>

using namespace std;

void print1dVector(vector<int> vec)
{
    int length = vec.size();

    cout << "{ ";
    for (int i = 0; i < length; i++)
    {
        cout << vec[i];
        if (i == (length - 1))
            cout << " ";
        else
            cout << ", ";
    }
    cout << "}" << endl;
}

// https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)

// Solution 2: Greedy with Binary Search

// Let's construct the idea from following example.
// Consider the example nums = [2, 6, 8, 3, 4, 5, 1], let's try to build the increasing subsequences starting with an empty one: sub1 = [].
// Let pick the first element, sub1 = [2].
// 6 is greater than previous number, sub1 = [2, 6]
// 8 is greater than previous number, sub1 = [2, 6, 8]
// 3 is less than previous number, we can't extend the subsequence sub1, but we must keep 3 because in the future there may have the longest subsequence start with [2, 3], sub1 = [2, 6, 8], sub2 = [2, 3].
// With 4, we can't extend sub1, but we can extend sub2, so sub1 = [2, 6, 8], sub2 = [2, 3, 4].
// With 5, we can't extend sub1, but we can extend sub2, so sub1 = [2, 6, 8], sub2 = [2, 3, 4, 5].
// With 1, we can't extend neighter sub1 nor sub2, but we need to keep 1, so sub1 = [2, 6, 8], sub2 = [2, 3, 4, 5], sub3 = [1].
// Finally, length of longest increase subsequence = len(sub2) = 4.

// In the above steps, we need to keep different sub arrays (sub1, sub2..., subk) which causes poor performance. But we notice that we can just keep one sub array, when new number x is not greater than the last element of the subsequence sub, we do binary search to find the smallest element >= x in sub, and replace with number x.
// Let's run that example nums = [2, 6, 8, 3, 4, 5, 1] again:
// Let pick the first element, sub = [2].
// 6 is greater than previous number, sub = [2, 6]
// 8 is greater than previous number, sub = [2, 6, 8]
// 3 is less than previous number, so we can't extend the subsequence sub. We need to find the smallest number >= 3 in sub, it's 6. Then we overwrite it, now sub = [2, 3, 8].
// 4 is less than previous number, so we can't extend the subsequence sub. We overwrite 8 by 4, so sub = [2, 3, 4].
// 5 is greater than previous number, sub = [2, 3, 4, 5].
// 1 is less than previous number, so we can't extend the subsequence sub. We overwrite 2 by 1, so sub = [1, 3, 4, 5].
// Finally, length of longest increase subsequence = len(sub) = 4.

// Complexity
// Time: O(N * logN), where N <= 2500 is the number of elements in array nums.
// Space: O(N), we can achieve O(1) in space by overwriting values of sub into original nums array.

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> sub;
        for (int x : nums)
        {
            // sub[sub.size() - 1]: value of the last index
            if (sub.empty() || sub[sub.size() - 1] < x)
                sub.push_back(x);
            else
            {
                auto it = lower_bound(sub.begin(), sub.end(), x); // Find the index of the smallest number >= x
                *it = x;                                          // Replace that number with x
            }
        }
        return sub.size();
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 0, 8, 4, 6};
    cout << sol.lengthOfLIS(nums) << endl;
}