#include <bits/stdc++.h>
// #include <iostream>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int pivot, left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            pivot = left + (right - left) / 2;
            if (target == nums[pivot])
                return pivot;
            if (target < nums[pivot])
                right = pivot - 1;
            else
                left = pivot + 1;
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

    cout << sol.search(nums, target) << endl;
}