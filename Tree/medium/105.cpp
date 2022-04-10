#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34538/My-Accepted-Java-Solution

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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildTree(0, 0, inorder.size() - 1, preorder, inorder);
    }

private:
    TreeNode *buildTree(int preStart, int inStart, int inEnd, vector<int> &preorder, vector<int> &inorder)
    {
        if (preStart >= preorder.size() || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);
        int inIndex = 0; // Index of current root in inorder
        for (int i = inStart; i <= inEnd; i++)
        {
            if (inorder[i] == root->val)
                inIndex = i;
        }

        root->left = buildTree(preStart + 1, inStart, inIndex - 1, preorder, inorder);
        root->right = buildTree(preStart + inIndex - inStart + 1, inIndex + 1, inEnd, preorder, inorder);
        return root;
    }
};

int main()
{
    Solution sol;
}