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

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/discuss/28335/My-accepted-Java-code

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return NULL;

        ListNode *dummy = new ListNode(0 == head->val ? 1 : 0); // to guarantee the dummy node is not same as the original head
        dummy->next = head;

        ListNode *pre = dummy;
        ListNode *cur = head;

        while (cur)
        {
            while (cur->next && cur->val == cur->next->val)
            {
                cur = cur->next;
            }

            if (pre->next == cur)
                pre = pre->next;
            else
                pre->next = cur->next;

            cur = cur->next;
        }

        return dummy->next;
    }
};

int main()
{
    Solution sol;
    // input: 1,2,3,3,4,4,5
    // output: 1,2,5
    ListNode *root = new ListNode(1);
    root->next = new ListNode(1);
    root->next->next = new ListNode(2);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(3);

    sol.deleteDuplicates(root);
    // printListNode(root);
}