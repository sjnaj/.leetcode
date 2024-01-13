/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

// @lc code=start

// Definition for singly-linked list.
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode(int x) : val(x), next(nullptr) {}
// };

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        // 相对速度差为 1，一定会相遇,且是在slow走完一圈之前,fast走完一圈之后被追上
        // 相遇时 slow=x+y,fast=x+y+n(c)=x+y+n(y+z)
        // 又2(x+y)=x+y+n(y+z)
        // x+y=n(y+z)
        // x=n(y+z)-y=(n-1)(y+z)+z=(n-1)c+z;
        // 环的入口就是相遇时到入口的距离加上n-1圈的长度
        // 此时从head出发一个慢指针，原慢指针继续走，它们会在入口相遇

        ListNode *fast = head, *slow = head;
        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                ListNode *index = head;
                while (index != slow)
                {
                    index = index->next;
                    slow = slow->next;
                }
                return index;
            }
        }
        return nullptr;
    }
};
// @lc code=end
