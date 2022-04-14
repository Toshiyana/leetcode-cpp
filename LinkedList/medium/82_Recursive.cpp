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
        if (!head || !head->next)
            return head;

        if (head->val != head->next->val)
        {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        else
        {
            while (head->next && head->val == head->next->val)
                head = head->next;

            return deleteDuplicates(head->next);
        }
    }
};

int main()
{
    Solution sol;
    // input: 1,2,3,3,4,4,5
    // output: 1,2,5
    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(3);
    root->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next = new ListNode(4);
    root->next->next->next->next->next->next = new ListNode(5);

    sol.deleteDuplicates(root);
    // printListNode(root);
}