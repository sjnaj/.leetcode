/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
#include <iostream>
// Definition for singly-linked list.
// using namespace std;
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //将list1作为头节点
        if(!list1||(list2&&list2->val<list1->val)){
            swap(list1,list2);
        }
        if(list1){
            list1->next=mergeTwoLists(list1->next,list2);
        }
        return list1;

    }
};
// @lc code=end

