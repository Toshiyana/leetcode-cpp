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

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> vals_level(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();

                int index = (leftToRight) ? i : (size - 1 - i);

                vals_level[index] = front->val;

                if (front->left)
                    q.push(front->left);

                if (front->right)
                    q.push(front->right);
            }
            leftToRight = !leftToRight;
            res.push_back(vals_level);
            // print2dVector(res);
        }
        return res;
    }
};

int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    sol.zigzagLevelOrder(root);
}