#include <bits/stdc++.h>
#include "./../../Utils/Utils.h"

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// easy to understand

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *cur = head;

        while (cur)
        {
            while (cur->next && (cur->val == cur->next->val))
                cur->next = cur->next->next;

            cur = cur->next;
        }

        return head;
    }
};

int main()
{
    Solution sol;
    // input: 1,1,2,3,3
    // output: 1,2,3
    ListNode *root = new ListNode(1);
    root->next = new ListNode(1);
    root->next->next = new ListNode(2);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(3);

    sol.deleteDuplicates(root);
    // printListNode(root);
}