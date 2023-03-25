#include <bits/stdc++.h>

//  Definition for singly-linked list.
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
    ListNode *middleNode(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }
        ListNode *curr = head;
        ListNode *forward = head->next;
        int i = 0;
        while (curr && forward)
        {
            curr = forward;
            forward = curr->next;
            i++;
        }

        curr = head;
        forward = head->next;
        int j = 0;
        int mid = ceil((i + 1) / 2);

        while (j < mid && forward)
        {
            curr = forward;
            forward = curr->next;
            j++;
        }
        return curr;
    }
};