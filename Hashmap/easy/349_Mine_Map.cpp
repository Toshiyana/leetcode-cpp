#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> nums1, vector<int> nums2)
    {
        unordered_map<int, int> indices;
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++)
            indices[nums1[i]] = i;

        for (int i = 0; i < nums2.size(); i++)
        {
            int numberToFind = nums2[i];
            if (indices.find(numberToFind) != indices.end()) // find numberToFind in indices
            {
                if (find(result.begin(), result.end(), numberToFind) == result.end()) // not found numberToFind in result
                    result.push_back(numberToFind);
            }
        }
        return result;
    }
};

int main()
{
    Solution sol;
}