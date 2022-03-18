#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    // answer1: easy to understand
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indices;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++)
        {
            int numberToFind = target - nums[i];

            if (indices.find(numberToFind) != indices.end()) // found in map
            {
                result.push_back(indices[numberToFind]);
                result.push_back(i);
                return result;
            }
            // when numberToFind was not found in map, add it to map
            indices[nums[i]] = i;
        }

        return result;
    }
};

class Solution2
{
public:
    // answer2: make short answer1's code
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> indices;

        for (int i = 0; i < nums.size(); i++)
        {
            if (indices.find(target - nums[i]) != indices.end())
                return {indices[target - nums[i]], i};

            indices[nums[i]] = i;
        }

        return {};
    }
};

int main()
{
    Solution sol;
    Solution2 sol2;

    vector<int> nums = {3, 2, 4};
    int target = 6;

    // sol.twoSum(nums, target);
    cout << sol2.twoSum(nums, target)[0] << endl;
}