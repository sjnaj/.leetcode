/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start

//  Definition for singly-linked list.
//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//         ListNode*pred=nullptr,*curr=head,*succ;
//         while(curr!=nullptr){
//             succ=curr->next;
//             curr->next=pred;
//             pred=curr;
//             curr=succ;
//         }
//         return pred;
//     }
// };
// class Solution {
// private:
//   ListNode* reverse(ListNode*curr,ListNode*pred){
//     if(curr==nullptr)return pred;
//     ListNode*succ=curr->next;
//     curr->next=pred;
//     return reverse(succ,curr);
//   }
// public:
//     ListNode* reverseList(ListNode* head) {
//         return reverse(head,nullptr);
//     }
// };

class Solution {
private:
 
public:
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* new_head=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return new_head;
    }
};
// @lc code=end

