#include <iostream>

struct ListNode
{
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr)
    {}

    ListNode(int x) : val(x), next(nullptr)
    {}

    ListNode(int x, ListNode* next) : val(x), next(next)
    {}
};

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while (l1 || l2)
        {
            int val1 = l1 ? l1->val : INT_MAX;
            int val2 = l2 ? l2->val : INT_MAX;

            if (val1 < val2)
            {
                curr->next = new ListNode(val1);
                l1 = l1->next;
            } else
            {
                curr->next = new ListNode(val2);
                l2 = l2->next;
            }
            curr = curr->next;
        }

        return head->next;
    }
};
