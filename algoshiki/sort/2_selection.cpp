#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://algo-method.com/tasks/440

void selectionSort(vector<int> &nums)
{
    for (int k = 0; k < nums.size() - 1; k++)
    {
        int minIdx = k;
        int minVal = nums[k];

        for (int i = k + 1; i < nums.size(); i++)
        {
            if (nums[i] < minVal)
            {
                minIdx = i;
                minVal = nums[i];
            }
        }
        swap(nums[k], nums[minIdx]);
    }
}

int main()
{
    vector<int> nums = {3, 1, 4, 5, 2, 3};
    selectionSort(nums);
    print1dVector(nums);
}