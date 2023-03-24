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
    ListNode *solve(ListNode *list1, ListNode *list2)
    {
        if (list1->next == NULL)
        {
            list1->next = list2;
            return list1;
        }

        ListNode *curr1 = list1;
        ListNode *next1 = list1->next;
        ListNode *curr2 = list2;
        ListNode *next2 = list2->next;

        while (curr1 && next1 && curr2)
        {
            if ((curr2->val >= curr1->val) && (curr2->val <= next1->val))
            {

                // addition of pointers to linkedlist
                curr1->next = curr2;
                next2 = curr2->next; // to keep track of the rest of list2
                curr2->next = next1;

                // now update pointers
                curr1 = curr2;
                curr2 = next2;
            }
            else
            {
                // move curr1 and next1
                curr1 = next1;
                next1 = next1->next;
                if (next1 == NULL)
                {
                    curr1->next = curr2;
                    return list1;
                }
            }
        }
        return list1;
    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        // if one of list1 and list2 is empty
        if (list1 == NULL)
        {
            return list2;
        }

        if (list2 == NULL)
        {
            return list1;
        }

        if (list1->val <= list2->val)
        {
            ListNode *ans = solve(list1, list2);
            return ans;
        }
        else
        {
            ListNode *ans = solve(list2, list1);
            return ans;
        }
        return 0;
    }
};