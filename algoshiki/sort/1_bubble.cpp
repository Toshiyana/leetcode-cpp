#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://algo-method.com/tasks/439/editorial

void bubbleSort(vector<int> &nums)
{
    for (int loop = 0; loop < nums.size(); loop++) // 無限ループ回避のため nums.size() 回で打ち切る
    {
        bool flag = false; // 交換があったかどうか
        for (int i = 0; i < nums.size() - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                swap(nums[i], nums[i + 1]);
                flag = true;
            }
        }

        if (!flag) // loopの間で、一度も交換がなかったらsort完了で終了
            return;
    }
}

int main()
{
    vector<int> nums = {3, 1, 4, 5, 2};
    bubbleSort(nums);
    print1dVector(nums);
}