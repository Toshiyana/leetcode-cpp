#include <bits/stdc++.h>

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

// Given a binary tree, print its nodes in inorder
void printInorder(TreeNode *node)
{
    if (!node)
        return;

    // first recur on left child
    printInorder(node->left);

    // then print the data of node
    cout << node->val << " ";

    // now recur on right child
    printInorder(node->right);
};

class Solution
{
public:
    // DFS (Depth First Search)
    // TC - O(num of nodes) as we are traversing all the nodes of the tree
    // SC - O(1) without taking the implicit recursive stack into consideration
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        int maxLeft = maxDepth(root->left);
        int maxRight = maxDepth(root->right);

        // cout << maxLeft << " " << maxRight << endl;

        return max(maxLeft, maxRight) + 1;
    }

    // BFS (Breadth First Search)
    // TC - O(n)
    // SC - O(n)
    int maxDepth_bfs(TreeNode *root)
    {
        if (!root)
            return 0;

        queue<TreeNode *> q;
        q.push(root);
        int depth = 0;

        while (!q.empty())
        {
            ++depth;
            int s = q.size();

            // cout << q.front()->val << endl;
            // cout << depth << endl;
            // cout << s << endl;
            // cout << endl;

            for (int i = 0; i < s; i++)
            {
                TreeNode *front = q.front();
                q.pop();

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
        }

        return depth;
    }
};

int main()
{
    Solution sol;

    struct TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // printInorder(root);
    // cout << sol.maxDepth(root);
    cout << sol.maxDepth_bfs(root);
}