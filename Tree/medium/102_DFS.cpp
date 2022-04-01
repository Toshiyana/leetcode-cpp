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

// https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33468/One-of-C%2B%2B-solutions-(preorder)

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;
        levelOrder(res, root, 0);
        return res;
    }

private:
    void levelOrder(vector<vector<int>> &res, TreeNode *root, int depth)
    {
        if (!root)
            return;
        if (res.size() == depth)
            res.push_back(vector<int>());

        res[depth].push_back(root->val);
        levelOrder(res, root->left, depth + 1);
        levelOrder(res, root->right, depth + 1);
    }
};

int main()
{
    Solution sol;
    // [1,2,3,4,5]
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);

    // [3,9,20,null,null,15,7]
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    print2dVector(sol.levelOrder(root));
}