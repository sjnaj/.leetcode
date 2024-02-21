/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0), *curr = dummy, *prev = nullptr, *next, *tmp,*tmp1;
        dummy->next = head;
        for (int i = 0; i < left - 1; i++)
        {
            curr = curr->next;
        }
        tmp=curr;
        curr = curr->next;
        tmp1 = curr;
        for (int i = 0; i < right - left + 1; i++)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        tmp1->next=curr;
        tmp->next = prev;
        return dummy->next;
    }
};
// @lc code=end
