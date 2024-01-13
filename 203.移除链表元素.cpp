/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
// Definition for singly-linked list.
/* struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
}; */

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)//不考虑释放结点内存
    {
        ListNode *h = head, *pred, *curr;
        while (h != nullptr&&h->val == val)//可以添加dummy head达到同样效果
        {
                h = h->next;
        }
        if (h == nullptr)
            return nullptr;
        pred = h;
        curr = h->next;
        while (curr!=nullptr)
        {
            if (curr->val == val)
            {
                curr = curr->next;
                pred->next = curr;
            }
            else
            {
                pred = curr;
                curr = curr->next;
            }
        }
        return h;
    }
};
// @lc code=end
