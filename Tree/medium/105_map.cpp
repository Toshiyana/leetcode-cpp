#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/34538/My-Accepted-Java-Solution/243852

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

// Instead of searching for the root value in inorder each time, you may store it in a map and look it up. Rewrote in C++.
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        return buildTree(0, 0, inorder.size() - 1, mp, preorder, inorder);
    }

private:
    TreeNode *buildTree(int preStart, int inStart, int inEnd, unordered_map<int, int> &mp, vector<int> &preorder, vector<int> &inorder)
    {
        if (preStart >= preorder.size() || inStart > inEnd)
            return NULL;

        TreeNode *root = new TreeNode(preorder[preStart]);
        int i = mp[preorder[preStart]];
        root->left = buildTree(preStart + 1, inStart, i - 1, mp, preorder, inorder);
        root->right = buildTree(preStart + 1 + i - inStart, i + 1, inEnd, mp, preorder, inorder);
        return root;
    }
};

int main()
{
    Solution sol;
}