#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/subarray-sum-equals-k/discuss/102121/C%2B%2B-prefix-sum-%2B-map

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int sum = 0, ans = 0; // cumlated sum, number of found subarray
        map<int, int> rec;    // prefix sum recorder
        rec[0]++;             // to take into account those subarrays that begin with index 0
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            ans += rec[sum - k];
            rec[sum]++;

            // cout << "sum: " << sum << endl;
            // cout << "rec[" << sum << " - " << k << "]: " << rec[sum - k] << ", ans: " << ans << endl;
            // cout << "rec[" << sum << "]: " << rec[sum] << endl;
            // cout << endl;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << sol.subarraySum(nums, k) << endl;
}