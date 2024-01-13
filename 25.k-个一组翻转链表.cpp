/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start
// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *bound = head;
        for (int i = 0; i < k; i++)
        {
            // 不足k个，不进行逆转
            if (bound == nullptr)
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
        head->next = reverseKGroup(curr, k);//k个一组逆置剩余部分
        return pred;
    }
};
// @lc code=end
