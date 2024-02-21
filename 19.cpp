#include <bits/stdc++.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *removeNthFromEnd(ListNode *head, int n)
{
    ListNode d{0};

    ListNode *dummy = &d, *fast = dummy, *slow = dummy;
    dummy->next = head;
    for (int i = 0; i < n + 1; i++)
    {
        fast = fast->next;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode *p = slow->next;
    slow->next = p->next;
    delete p;
    return dummy->next;
}