struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *bound = head;
    for (int i = 0; i < k; i++)
    {
        if (!bound)
            return head;
        bound = bound->next;
    }
    ListNode *curr = head, *pred = nullptr, *succ;
    for (int i = 0; i < k; i++)
    {
        succ = curr->next;
        curr->next = pred;
        pred = curr;
        curr = succ;
    }
    //nullptr在这里被覆盖掉。
    head->next = reverseKGroup(curr, k);
    return pred;
}
