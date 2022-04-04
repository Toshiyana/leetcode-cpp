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

// https://leetcode.com/problems/binary-tree-inorder-traversal/discuss/31231/C%2B%2B-Iterative-Recursive-and-Morris

// Recursive solution
// Time Complexity: O(n) time
// Space Complexity: O(n) space

class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes;
    }

private:
    void inorder(TreeNode *root, vector<int> &nodes)
    {
        if (!root)
            return;

        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(7);
    root->right->right->left = new TreeNode(6);
    root->right->right->right = new TreeNode(8);

    print1dVector(sol.inorderTraversal(root));
}