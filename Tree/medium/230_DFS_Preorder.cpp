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
    int kthSmallest(TreeNode *root, int k)
    {
        vector<int> res;

        dfs(root, res);

        sort(res.begin(), res.end());

        return res[k - 1];
    }

private:
    void dfs(TreeNode *root, vector<int> &res)
    {
        if (!root)
            return;

        res.push_back(root->val);

        dfs(root->left, res);
        dfs(root->right, res);
    }
};

int main()
{
    Solution sol;
    // root = [3,1,4,null,2], k = 1
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    cout << sol.kthSmallest(root, 2) << endl;
}