#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

using namespace std;

// approach1: set
// TC - O(N)
// SC - O(N)

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> st;
        for (int n : nums)
        {
            if (st.find(n) != st.end())
                return true;
            st.insert(n);
        }
        return false;
    }
};

// approach2: sort
// TC - O(N log N)
// SC - O(1) - not counting the memory used by sort

class Solution2
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                return true;
        }
        return false;
    }
};

// approach3 (TLE): naive approach
// TC - O(N^2)
// SC - O(1)
class Solution3
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] == nums[j])
                    return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
}