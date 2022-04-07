#include <bits/stdc++.h>
// #include "./../../Utils/Utils.h"

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

// https://leetcode.com/problems/palindrome-linked-list/discuss/64490/My-easy-understand-C%2B%2B-solution

class Solution
{
public:
    ListNode *temp;
    bool isPalindrome(ListNode *head)
    {
        temp = head;
        return check(head);
    }

private:
    bool check(ListNode *p)
    {
        if (p == NULL)
            return true;

        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};

int main()
{
    Solution sol;
}