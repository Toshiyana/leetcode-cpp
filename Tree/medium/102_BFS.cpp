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

// https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33443/C%2B%2B-solution-using-only-one-queue-use-a-marker-NULL

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (!root)
            return res;

        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);

        vector<int> vals_level;

        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();

            if (front == NULL) // そのlevelのvalを追加し終えた時
            {
                res.push_back(vals_level);
                vals_level.resize(0); // 要素数を0にする（初期化）
                if (q.size() > 0)
                    q.push(NULL); // mark of the level end
            }
            else
            {
                vals_level.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    // [1,2,3,4,5]
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);

    // [3,9,20,null,null,15,7]
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    print2dVector(sol.levelOrder(root));
}