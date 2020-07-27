class MyLinkedList {
    // Definition for doubly-linked list.
    struct DoublyListNode {
        int val;
        DoublyListNode *prev, *next;
        DoublyListNode(int x) : val(x), prev(NULL), next(NULL) {}
    };
    
    int size;
    DoublyListNode *head, *tail;
    
    void print()
    {
        cout << "head:" << head->val << " tail:" << tail->val << " size:" << this->size << endl;
        DoublyListNode *cur = this->head;
        while(cur)
        {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << ", ";
        cur = this->tail;
        while(cur)
        {
            cout << cur->val << " ";
            cur = cur->prev;
        }
        cout << endl;
    }
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if(index < 0 || index >= this->size)
            return -1;
        
        if(index < this->size / 2)
        {
            DoublyListNode *cur = this->head;
            for(int i = 0; i < this->size; i++)
            {
                if(i == index)
                    return cur->val;
                
                cur = cur->next;
            }
        }
        else
        {
            DoublyListNode *cur = this->tail;
            for(int i = this->size - 1; i >= 0; i--)
            {
                if(i == index)
                    return cur->val;
                
                cur = cur->prev;
            }
        }
        
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        DoublyListNode *cur = new DoublyListNode(val);
        
        if(!head)
        {
            head = tail = cur;
        }
        else
        {
            cur->next = head;
            head->prev = cur;
            head = cur;
        }
        
        this->size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        DoublyListNode *cur = new DoublyListNode(val);
        
        if(!tail)
        {
            tail = head = cur;
        }
        else
        {
            tail->next = cur;
            cur->prev = tail;
            tail = cur;
        }
        
        this->size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index < 0 || index > this->size)
            return;
        
        if(index == 0)
        {
            addAtHead(val);
        }
        else if(index == this->size)
        {
            addAtTail(val);
        }
        else
        {
            DoublyListNode *node = new DoublyListNode(val);
            DoublyListNode *cur = NULL;
            if(index < this->size / 2)
            {
                cur = this->head;
                for(int i = 0; i < this->size && i != index; i++)
                {
                    cur = cur->next;
                }
            }
            else
            {
                cur = this->tail;
                for(int i = this->size - 1; i >= 0 && i != index; i--)
                {
                    cur = cur->prev;
                }
            }
            node->next = cur;
            node->prev = cur->prev;
            cur->prev->next = node;
            cur->prev = node;
            
            this->size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index < 0 || index >= this->size)
            return;
        
        if(this->size == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
            
            this->size = 0;
            return;
        }
        
        DoublyListNode *cur = NULL;
        if(index < this->size / 2)
        {
            cur = head;
            for(int i = 0; i < this->size && i != index; i++)
            {
                cur = cur->next;
            }
        }
        else
        {
            cur = tail;
            for(int i = this->size - 1; i >= 0 && i!= index; i--)
            {
                cur = cur->prev;
            }
        }

        if(cur == head)
        {
            cur->next->prev = NULL;
            head = cur->next;
        }
        else if(cur == tail)
        {
            cur->prev->next = NULL;
            tail = cur->prev;
        }
        else
        {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        delete cur;
        
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