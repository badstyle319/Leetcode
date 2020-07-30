class MyCircularQueue {
    int *buf;
    int size;
    int head;
    int tail;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        this->size = k;
        
        this->buf = new int[k];
        memset(this->buf, 0, sizeof(int) * k);
        
        this->head = -1;
        this->tail = -1;
    }
    
    ~MyCircularQueue()
    {
        delete[] this->buf;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(this->isFull())
            return false;
        
        this->tail++;
        this->tail %= this->size;
        
        if(this->head == -1)
            this->head = this->tail;
        
        this->buf[tail] = value;

        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty())
            return false;
        
        if(this->head == this->tail)
        {
            this->head = -1;
            this->tail = -1;
            
            return true;
        }
        
        this->head++;
        this->head %= this->size;
        
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty())
            return -1;
        
        return this->buf[this->head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty())
            return -1;
        
        return this->buf[this->tail];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return (this->head == -1);
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return (this->tail+1) % this->size == this->head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */