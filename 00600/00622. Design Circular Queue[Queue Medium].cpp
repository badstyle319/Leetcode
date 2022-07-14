class MyCircularQueue {
    int size, front, rear;
    vector<int> buffer;
public:
    MyCircularQueue(int k) {
        size = k;
        buffer.resize(size, -1);
        front = rear = -1;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        
        if(isEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        buffer[rear] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        
        buffer[front] = -1;
        if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1 ) % size;
        }
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return buffer[front];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return buffer[rear];
    }
    
    bool isEmpty() {
        return front == -1;
    }
    
    bool isFull() {
        return (rear + 1) % size == front;
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