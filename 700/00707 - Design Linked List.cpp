class MyLinkedList {
    // Definition for singly-linked list.
    struct SinglyListNode {
        int val;
        SinglyListNode *next;
        SinglyListNode(int x) : val(x), next(NULL) {}
    };
    
    int size;
    SinglyListNode* head;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->size = 0;
        this->head = NULL;
    }
    
    void print()
    {
        cout << "size: " << this->size << endl;
        SinglyListNode* cur = head;
        while(cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= this->size)
            return -1;
        
        SinglyListNode* cur = head;
        while(index--)
        {
            cur = cur->next;
        }

        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SinglyListNode* node = new SinglyListNode(val);
        if(!head)
            head = node;
        else
        {
            node->next = head;
            head = node;
        }
        this->size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(!head)
        {
            addAtHead(val);
        }
        else
        {
            addAtIndex(this->size, val);
        }
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > this->size)
            return;
        
        // cout << __FUNCTION__ << " [" << index << "," << val << "]" << endl;
        if(!head || index == 0)
        {
            addAtHead(val);
            // print();
            return;
        }        
        
        SinglyListNode* newNode = new SinglyListNode(val);
        SinglyListNode* cur = head;
        while(--index)
        {
            cur = cur->next;
        }
        
        newNode->next = cur->next;
        cur->next = newNode;
        
        this->size++;
        // print();
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= size)
            return;
        
        SinglyListNode* dNode;
        if(index == 0)
        {
            dNode = head;
            head = head->next;
        }
        else
        {
            SinglyListNode* cur = head;
            while(--index)
            {
                cur = cur->next;
            }
            dNode = cur->next;
            cur->next = dNode->next;
        }
        delete dNode;
        this->size--;
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