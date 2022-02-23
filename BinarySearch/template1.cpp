#include <bits/stdc++.h>

using namespace std;

// Simple binary search same as 704

class Solution
{
public:
    int binarySearch(vector<int> &nums, int target)
    {
        int mid, left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            mid = left + (right - left) / 2;
            if (target == nums[mid])
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int target;

    nums = {-1, 0, 3, 5, 9, 12};
    target = 9;

    cout << sol.binarySearch(nums, target) << endl;
}