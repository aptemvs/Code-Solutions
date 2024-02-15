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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head)
            return head;

        ListNode* dummy_head = head;
        while (ListNode* child = dummy_head->next)
        {
            if (dummy_head->val == child->val)
            {
                dummy_head->next = child->next;
                delete child;
            } else
            {
                dummy_head = child;
                child = child->next;
            }
        }
        return head;
    }
};
