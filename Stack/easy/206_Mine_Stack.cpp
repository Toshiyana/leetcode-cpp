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
    ListNode *reverseList(ListNode *head)
    {
        stack<int> st;

        // add node's value to stack
        ListNode *tail = head;
        while (tail)
        {
            st.push(tail->val);
            tail = tail->next;
        }

        // make reversed nodes
        tail = head; // initialize
        while (tail)
        {
            tail->val = st.top();
            st.pop();
            tail = tail->next;
        }

        return head;
    }
};

int main()
{
    Solution sol;
    vector<int> head = {1, 2, 3, 4, 5};

    ListNode *root = new ListNode(1);
    root->next = new ListNode(2);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(4);
    root->next->next->next->next = new ListNode(5);

    printListNode(sol.reverseList(root));
}