#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/kth-largest-element-in-a-stream/discuss/150609/C%2B%2B-super-easy-28ms-solution-beats-100!

class KthLargest
{
public:
    // 昇順に値を取り出す
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;

    // constructor
    KthLargest(int k, vector<int> &nums)
    {
        size = k;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            if (pq.size() > size)
                pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > size)
            pq.pop();
        return pq.top();
    }
};

int main()
{
    int k = 3;
    // vector<int> nums = {4, 5, 8, 2};
    vector<int> nums = {4, 5};
    KthLargest *obj = new KthLargest(k, nums);
    int param_1 = obj->add(3);

    cout << param_1 << endl;
}