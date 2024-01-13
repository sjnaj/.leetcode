/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList
{
public:
    struct Node
    {
        int val;
        Node *next;
    };
    Node *head;
    Node *curr;
    int size;

    MyLinkedList()
    {
        head = new Node();
        head->next = nullptr;
        size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            return -1;
        }

        for (curr = head->next; index > 0; curr = curr->next, index--)
            ;
        return curr->val;
    }

    void addAtHead(int val)
    {
        curr = new Node();
        curr->val = val;
        curr->next = head->next;
        head->next = curr;
        ++size;
    }

    void addAtTail(int val)
    {
        curr = head;
        while (curr && curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = new Node();
        curr->next->val = val;
        curr->next->next = nullptr;
        ++size;
    }

    void addAtIndex(int index, int val)
    {
        if (index < 0 || index > size)
        {
            return;
        }
        Node *new_node = new Node();
        new_node->val = val;
        for (curr = head; index > 0; index--, curr = curr->next)
            ;
        new_node->next = curr->next;
        curr->next = new_node;
        ++size;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
        {
            return;
        }
        for (curr = head; index > 0; index--, curr = curr->next)
            ;
        curr->next = curr->next->next;
        --size;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end
int main()
{
    MyLinkedList *obj = new MyLinkedList();
    obj->addAtTail(1);
    obj->get(0);
    obj->addAtTail(3);
    obj->addAtIndex(1, 2);
    obj->get(1);
    obj->deleteAtIndex(1);
}