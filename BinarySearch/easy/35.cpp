#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int mid, left = 0, right = nums.size() - 1;

        while (left <= right)
        {
            mid = left + (right - left) / 2;

            if (target == nums[mid])
                return mid;
            if (target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }

        return left;
    }
};

int main()
{
    Solution sol;
}