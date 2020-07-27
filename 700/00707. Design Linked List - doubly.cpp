class MyLinkedList {
    // Definition for singly-linked list.
    struct DoublyListNode {
        int val;
        DoublyListNode *prev, *next;
        DoublyListNode(int x) : val(x), prev(NULL), next(NULL) {}
    };
    
    int size;
    DoublyListNode *head, *tail;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        DoublyListNode *cur = head;
        
        while(index--)
            cur = cur->next;
        
        return cur;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        DoublyListNode *node = new DoublyListNode(val);
        
        if(!head)
            head = node;
        else
        {
            node->next = head;
            head->prev = node;
            head = node;
        }
        
        this->size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        DoublyListNode *node = new DoublyListNode(val);
        
        if(!tail)
            tail = node;
        else
        {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        
        this->size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > this->size)
            return;
        
        if(index == 0)
            addAtHead(val);
        else if(index == this->size)
            addAtTail(val);
        else
        {
            
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
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