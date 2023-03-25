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
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
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
    ListNode *head = new ListNode(6);
    head->next = new ListNode(5);
    head->next->next = new ListNode(11);
    head->next->next->next = new ListNode(3);
    s.displayList(head);
    head = s.middleNode(head);
    s.displayList(head);
}