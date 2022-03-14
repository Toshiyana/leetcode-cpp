// https://leetcode.com/problems/longest-increasing-subsequence/discuss/1326308/C%2B%2BPython-DP-Binary-Search-BIT-Solutions-Picture-explain-O(NlogN)

// Solution 3: Binary Indexed Tree (Increase BASE of nums into one-base indexing)

// Let f[x] is the length of longest increase subsequence , where all number in the subsequence <= x. This is the max element in indices [1..x] if we build the Binary Indexed Tree (BIT)
// Since -10^4 <= nums[i] <= 10^4, we can convert nums into 1 <= nums[i] <= 2*10^4+1 by plus BASE=10001 to store into the BIT.
// We build Max BIT, which has 2 operators:
// get(idx): Return the maximum value of indices in range [1..idx].
// update(idx, val): Update a value val into BIT at index idx.
// Iterate numbers i in range [0..n-1]:
// subLongest = bit.get(nums[i] - 1) // Get longest increasing subsequence so far, which idx < nums[i], or idx <= nums[i] - 1.
// bit.update(nums[i], subLongest + 1) // Update latest longest to the BIT.
// The answer is bit.get(20001) // Maximum of all elements in the BIT

// Complexity

// Time: O(N * logMAX), where MAX = 20000 is the difference between minimum and maximum elements in nums, N <= 2500 is the number of elements in array nums.
// Space: O(MAX)

#include <bits/stdc++.h>

using namespace std;

class MaxBIT
{ // One-based indexing
    vector<int> bit;

public:
    MaxBIT(int size)
    {
        bit.resize(size + 1);
    }
    int get(int idx)
    {
        int ans = 0;
        for (; idx > 0; idx -= idx & -idx)
            ans = max(ans, bit[idx]);
        return ans;
    }
    void update(int idx, int val)
    {
        for (; idx < bit.size(); idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }
};
class Solution
{ // 16 ms, faster than 72.16%
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int BASE = 10001;
        MaxBIT bit(20001);
        for (int x : nums)
        {
            int subLongest = bit.get(BASE + x - 1);
            bit.update(BASE + x, subLongest + 1);
        }
        return bit.get(20001);
    }
};

int main()
{
    Solution sol;
}