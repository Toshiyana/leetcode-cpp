#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int s = 0, e = nums.size() - 1, mid;

        while (s <= e)
        {
            mid = s + (e - s) / 2;

            if (target == nums[mid])
                return mid;

            else if (nums[mid] >= nums[s])
            { // nums[s...mid]が昇順の時
                if (target < nums[mid] && target >= nums[s])
                {
                    // target < nums[mid] かつ
                    // midより左にtargetがある時は、target >= nums[s]。
                    // この時のみ、e = mid -1。
                    // (Rotateでmidよりtargetが右にある時は、target < nums[s]
                    //  -> midよりtargetが右なので、s = mid + 1)
                    e = mid - 1;
                }
                else
                    s = mid + 1;
            }
            else
            { // nums[s...mid]が昇順でない時(nums[mid...e]が昇順の時)
                if (target > nums[mid] && target <= nums[e])
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }

        return -1;
    }
};

int main()
{
    Solution sol;
    vector<int> nums;
    int target;

    nums = {4, 5, 6, 7, 0, 1, 2};
    target = 0;

    // nums = {5, 1, 3};
    // target = 5;
    cout << sol.search(nums, target) << endl;
}