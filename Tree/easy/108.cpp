#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return nullptr;
        if (nums.size() == 1)
            return new TreeNode(nums[0]);

        int mid = nums.size() / 2;
        TreeNode *root = new TreeNode(nums[mid]);

        vector<int> leftInts(nums.begin(), nums.begin() + mid);
        vector<int> rightInts(nums.begin() + mid + 1, nums.end());

        // print1dVector(leftInts);
        // print1dVector(rightInts);
        // cout << endl;

        root->left = sortedArrayToBST(leftInts);
        root->right = sortedArrayToBST(rightInts);

        return root;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-10, -3, 0, 5, 9};
    sol.sortedArrayToBST(nums);
}