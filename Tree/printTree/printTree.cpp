#include <bits/stdc++.h>

using namespace std;

// reference: https://www.geeksforgeeks.org/dfs-traversal-of-a-tree-using-recursion/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
// ----------------------------------------------------------------
// Given a binary tree, print its nodes in inorder
// ----------------------------------------------------------------
void printInorder(TreeNode *node)
{
    if (!node)
        return;

    // first recur on left child
    printInorder(node->left);

    // then print the value of node
    cout << node->val << " ";

    // now recur on right child
    printInorder(node->right);
};

// ----------------------------------------------------------------
// Given a binary tree, print its nodes in preorder
// ----------------------------------------------------------------
void printPreorder(TreeNode *node)
{
    if (!node)
        return;

    // print the value of node
    cout << node->val << " ";

    // recur on left child
    printPreorder(node->left);

    // recur on right child
    printPreorder(node->right);
};

// ----------------------------------------------------------------
// Given a binary tree, print its nodes in postorder
// ----------------------------------------------------------------
void printPostorder(TreeNode *node)
{
    if (!node)
        return;

    // recur on left child
    printPostorder(node->left);

    // recur on right child
    printPostorder(node->right);

    // print the value of node
    cout << node->val << " ";
};

int main()
{
    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // printInorder(root); // 4 2 5 1 3
    // printPreorder(root); // 1 2 4 5 3
    printPostorder(root); // 4 5 2 3 1
}