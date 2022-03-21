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

// https://leetcode.com/problems/merge-two-binary-trees/discuss/588123/~100.00-fast-in-run-time-and-memory-RecursiveIterativeBFSDFS

// Time complexity : O(n). We traverse over a total of n nodes. Here, nn refers to the smaller of the number of nodes in the two trees.
// Space complexity : O(n). The depth of stack can grow upto n in case of a skewed tree.

class Solution
{
public:
    // pattern1: Iterative: Using Queue
    TreeNode *mergeTrees(TreeNode *n1, TreeNode *n2)
    {
        if (!n1 && !n2)
            return nullptr;
        if (!n1 || !n2)
            return n1 ? n1 : n2;

        queue<TreeNode *> q1, q2;
        q1.push(n1);
        q2.push(n2);

        while (!q1.empty() && !q2.empty())
        {
            TreeNode *f1 = q1.front();
            TreeNode *f2 = q2.front();
            q1.pop();
            q2.pop();

            f1->val += f2->val;

            if (!f1->left && f2->left)
                f1->left = f2->left;
            else if (f1->left && f2->left)
            {
                q1.push(f1->left);
                q2.push(f2->left);
            }

            if (!f1->right && f2->right)
                f1->right = f2->right;
            else if (f1->right && f2->right)
            {
                q1.push(f1->right);
                q2.push(f2->right);
            }
        }
        return n1; // n1とf1の先頭nodeのアドレスは、ポインタ変数なので同じ
    }

    // pattern2: Iterative: Using Stack (Queueとほぼ同じ。Queueだけできれば良さそう。)
    // 参照： https://leetcode.com/problems/merge-two-binary-trees/discuss/588123/~100.00-fast-in-run-time-and-memory-RecursiveIterativeBFSDFS
};

int main()
{
    Solution sol;
}