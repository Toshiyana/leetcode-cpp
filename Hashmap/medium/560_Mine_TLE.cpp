#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// Brute force (TLE)

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int l = 0, r = 0, res = 0, n = nums.size();

        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k)
                    res++;
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
}