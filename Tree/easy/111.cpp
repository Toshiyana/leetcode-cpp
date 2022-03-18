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

class Solution
{
public:
    // // https://leetcode.com/problems/minimum-depth-of-binary-tree/discuss/36071/BFS-C%2B%2B-8ms-Beats-99.94-submissions
    // BFS (Breadth First Search)
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        queue<TreeNode *> q;
        q.push(root);

        int depth = 0;

        while (!q.empty())
        {
            int s = q.size();
            depth++;
            for (int i = 0; i < s; i++)
            {

                TreeNode *front = q.front();
                q.pop();

                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
                if (front->left == NULL && front->right == NULL)
                    return depth;
            }
        }
        return -1; // For the compiler thing. The code never runs here.
    }

    // https://leetcode.com/problems/minimum-depth-of-binary-tree/discuss/36153/My-concise-c%2B%2B-solution
    // DFS (Depth First Search)
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;

        int minLeft = minDepth(root->left);
        int minRight = minDepth(root->right);

        // 一方にしかノードが存在しない場合
        if (!root->left)
            return minRight + 1;
        if (!root->right)
            return minLeft + 1;

        return min(minLeft, minRight) + 1;
    }
};

int main()
{
    // [2,null,3,null,4,null,5,null,6]
    // TreeNode *root = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->right->right = new TreeNode(4);
    // root->right->right->right = new TreeNode(5);
    // root->right->right->right->right = new TreeNode(6);

    // [1,2,3,4,5]
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution sol;
    cout << sol.minDepth(root) << endl;
}