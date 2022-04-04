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

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
            return NULL;

        int c = (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        ListNode *newHead = new ListNode(c % 10), *next = l1 ? l1->next : NULL;
        c /= 10;

        if (next)
            next->val += c;
        else if (c)
            next = new ListNode(c);

        newHead->next = addTwoNumbers(l2 ? l2->next : NULL, next);
        return newHead;
    }
};

int main()
{
    Solution sol;
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    sol.addTwoNumbers(l1, l2);
}