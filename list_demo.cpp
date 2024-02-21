struct ListNode{
    ListNode* next;
    int val;
};

ListNode* returnKNode(ListNode*head,int k){

    ListNode *fast=head,*slow=head;
    for(int i=0;i<k;i++){
        if(!fast)return nullptr;
        fast=fast->next;
    }
    while(fast){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}

