#include <bits/stdc++.h>
using namespace std;

// https://qiita.com/drken/items/97e37dd6143e33a64c8c

// 配列の中から目的値keyのindexを返す
// * 目的値が複数ある場合、どれか1つを返す
// * 目的値がない場合、-1を返す
int binary_search(vector<int> &nums, int key)
{
    int left = 0, right = (int)nums.size() - 1;
    while (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] == key)
            return mid;
        else if (nums[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main()
{
    vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
    sort(a.begin(), a.end());
    cout << binary_search(a, 51) << endl;
}