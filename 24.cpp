struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
ListNode *swapPairs(ListNode *head)
{
    ListNode d{0};
    ListNode *dummy = &d, *t1, *t2, *curr = dummy;
    dummy->next = head;
    while (curr->next && curr->next->next)
    {
        t1 = curr->next->next->next;
        t2 = curr->next;
        curr->next->next->next = t2;
        curr->next = curr->next->next;
        t2->next = t1;
        curr = t2;
    }
    return dummy->next;
}