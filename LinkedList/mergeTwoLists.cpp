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
        // if list has only one element, we append list2 to it
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
                // move curr1 and next1 forward
                curr1 = next1;
                next1 = next1->next;
                if (next1 == NULL)
                {
                    // if list1 is over, we append list2 and return
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
        // if the first element in list1 is smaller, then we start with list1
        if (list1->val <= list2->val)
        {
            ListNode *ans = solve(list1, list2);
            return ans;
        }
        // if the first element in list2 is smaller, then we start with list2
        else
        {
            ListNode *ans = solve(list2, list1);
            return ans;
        }
        return 0;
    }

    void displayList(ListNode *head)
    {
        ListNode *current = head;
        while (current->next)
        {
            cout << current->val << "->";
            current = current->next;
        }
        cout << current->val << endl;
    }
};

int main()
{
    Solution s = Solution();
    ListNode *list1 = new ListNode(6);
    list1->next = new ListNode(7);
    list1->next->next = new ListNode(11);
    list1->next->next->next = new ListNode(14);
    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(7);
    list2->next->next = new ListNode(13);
    list2->next->next->next = new ListNode(15);
    cout << "list 1: ";
    s.displayList(list1);
    cout << "list 2: ";
    s.displayList(list2);
    list1 = s.mergeTwoLists(list1, list2);
    s.displayList(list1);
}