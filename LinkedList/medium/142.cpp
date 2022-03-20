#include <bits/stdc++.h>

using namespace std;

// https://leetcode.com/problems/linked-list-cycle-ii/discuss/44781/Concise-O(n)-solution-by-using-C%2B%2B-with-Detailed-Alogrithm-Description

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
    ListNode *detectCycle(ListNode *head)
    {
        if (!head)
            return NULL;

        ListNode *slow = head, *fast = head, *entry = head; // entry: entry location of cycle
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) // まず、Cycleが存在するか確認
            {
                while (slow != entry)
                {
                    // 次に、一個一個pointerを進めてCycleの始点を探す
                    slow = slow->next;
                    entry = entry->next; // find the entry location of the Cycle
                }
                return entry;
            }
        }
        return NULL;
    }
};

int main()
{
    Solution sol;
}