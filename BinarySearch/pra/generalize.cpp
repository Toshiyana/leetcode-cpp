#include <bits/stdc++.h>
using namespace std;

// https://qiita.com/drken/items/97e37dd6143e33a64c8c

// <一般化した二分探索法> (std::lower_bound()と同じ)
// 配列aの中から目的値key以上の最小のindexを返す
// * leftは常に条件を満たさない
// * rightは常に条件を満たす
// * right - left = 1 になるまで範囲を狭める (最後はrightが条件を満たす最小)

bool isOK(vector<int> &nums, int index, int key)
{
    if (nums[index] >= key)
        return true;
    else
        return false;
}

int binary_search(vector<int> &nums, int key)
{
    int left = -1;           // 「index = 0」が条件を満たすこともあるので、初期値-1
    int right = nums.size(); // 「index = nums.size() - 1」が条件を満たさないことがあるので、初期値nums.size()

    while (right - left > 1)
    {
        int mid = left + (right - left) / 2;

        if (isOK(nums, mid, key))
            right = mid;
        else
            left = mid;
    }
    return right;
}

int main()
{
    vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};
    sort(a.begin(), a.end());
    cout << binary_search(a, 51) << endl;
}