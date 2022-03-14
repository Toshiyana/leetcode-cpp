// Solution 4: Binary Indexed Tree (Compress nums into values in [1...N])

// In solution 2, -10^4 <= nums[i] <= 10^4 is small enough, so we can store in our Binary Indexed Tree (BIT).
// Can we store when -10^9 <= nums[i] <= 10^9 is very big? In that case, we can compress our nums array while keeping the relative comparation order between numbers.
// How to compress?
// In the nums array length N, where N <= 2500, there are maximum N different numbers.
// We can get the unique values of numbers in nums, and sort those values in increasing order, let name it uniqueSorted.
// Then we traverse i in range [0..n-1], we get the compressed value of nums[i] by looking the index in uniqueSorted.
// As the result, elemenents in nums is compressed into values in range [1...N].

// Complexity:

// Time: O(N*logN), where N <= 2500 is the number of elements in array nums.
// Space: O(N)

#include <bits/stdc++.h>

using namespace std;

class MaxBIT
{
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
{ // 12 ms, faster than 75.90%
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int nUnique = compress(nums);
        MaxBIT bit(nUnique);
        for (int x : nums)
        {
            int subLongest = bit.get(x - 1);
            bit.update(x, subLongest + 1);
        }
        return bit.get(nUnique);
    }
    int compress(vector<int> &arr)
    {
        vector<int> uniqueSorted(arr);
        sort(uniqueSorted.begin(), uniqueSorted.end());
        uniqueSorted.erase(unique(uniqueSorted.begin(), uniqueSorted.end()), uniqueSorted.end()); // Remove duplicated values
        for (int &x : arr)
            x = lower_bound(uniqueSorted.begin(), uniqueSorted.end(), x) - uniqueSorted.begin() + 1;
        return uniqueSorted.size();
    }
};