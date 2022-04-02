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

// https://leetcode.com/problems/validate-binary-search-tree/discuss/32112/Learn-one-iterative-inorder-traversal-apply-it-to-multiple-tree-questions-(Java-Solution)

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;

        stack<TreeNode *> st;

        TreeNode *pre = NULL;

        while (root || !st.empty())
        {
            while (root)
            {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();

            if (pre && root->val <= pre->val)
                return false;

            pre = root;
            root = root->right;
        }
        return true;
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