#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// https://leetcode.com/problems/merge-two-binary-trees/discuss/104308/JavaC%2B%2B-Clean-Code-Unique-Node-or-Shared-Node-5-liner
// https://leetcode.com/problems/merge-two-binary-trees/discuss/588123/~100.00-fast-in-run-time-and-memory-RecursiveIterativeBFSDFS

// Time complexity : O(m). A total of m nodes need to be traversed. Here, m represents the minimum number of nodes from the two given trees.
// Space complexity : O(m). The depth of the recursion tree can go upto m in the case of a skewed tree. In average case, depth will be ****O(logm).

class Solution
{
public:
    // pattern1: create new node (good at memory)
    TreeNode *mergeTrees(TreeNode *n1, TreeNode *n2)
    {
        if (!n1 && !n2)
            return nullptr;

        TreeNode *node = new TreeNode((n1 ? n1->val : 0) + (n2 ? n2->val : 0));
        node->left = mergeTrees((n1 ? n1->left : nullptr), (n2 ? n2->left : nullptr));
        node->right = mergeTrees((n1 ? n1->right : nullptr), (n2 ? n2->right : nullptr));
        return node;
    }

    // pattern2: share node(simpler, but not good at memory)
    // nodeを共有すると、古いツリーのnodeが削除されると、新しいツリーのnodeも破壊されてしまうので良くない。
    TreeNode *mergeTrees(TreeNode *n1, TreeNode *n2)
    {
        if (!n1 || !n2)
            return n1 ? n1 : n2; // share node

        TreeNode *node = new TreeNode(n1->val + n2->val);
        node->left = mergeTrees(n1->left, n2->left);
        node->right = mergeTrees(n1->right, n2->right);
        return node;
    }
};

int main()
{
    Solution sol;
}