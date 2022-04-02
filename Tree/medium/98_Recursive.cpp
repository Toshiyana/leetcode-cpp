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

// https://leetcode.com/problems/validate-binary-search-tree/discuss/32104/C%2B%2B-in-order-traversal-and-please-do-not-rely-on-buggy-INT_MAX-INT_MIN-solutions-any-more

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        TreeNode *prev = NULL;
        return validate(root, prev);
    }

private:
    bool validate(TreeNode *node, TreeNode *&prev) // wrong answer when *prev. I don't know the reason.
    {
        if (!node)
            return true;
        if (!validate(node->left, prev))
            return false;
        if (prev && prev->val >= node->val)
            return false;
        prev = node;
        return validate(node->right, prev);
    }
};

int main()
{
    Solution sol;
    // root = [2, 1, 3]
    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    // root = [5,4,6,null,null,3,7]
    // [5,4,6,null,null,3,7] not a validate binary tree
    // https://leetcode.com/problems/validate-binary-search-tree/discuss/1388739/why-is-546nullnull37-not-a-validate-binary-tree

    // TreeNode *root = new TreeNode(5);
    // root->left = new TreeNode(4);
    // root->right = new TreeNode(6);

    // root->right->left = new TreeNode(3);
    // root->right->right = new TreeNode(7);

    cout << sol.isValidBST(root) << endl;
}