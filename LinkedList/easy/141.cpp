#include <bits/stdc++.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;

        ListNode *slow = head, *fast = head;

        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            // cout << "slow: " << slow->val << endl;
            // cout << "fast: " << fast->val << endl;
            // cout << endl;

            if (slow == fast) // valでなく、nodeのアドレスが同じか判断
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;

    ListNode *root = new ListNode(3);
    root->next = new ListNode(2);
    root->next->next = new ListNode(0);
    root->next->next->next = new ListNode(-4);
    root->next->next->next->next = root->next;

    cout << sol.hasCycle(root) << endl;
}