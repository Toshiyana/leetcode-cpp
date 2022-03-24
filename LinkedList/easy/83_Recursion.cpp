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

// https://leetcode.com/problems/remove-duplicates-from-sorted-list/discuss/28625/3-Line-JAVA-recursive-solution

// hard to understand (83.cpp is best)
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
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