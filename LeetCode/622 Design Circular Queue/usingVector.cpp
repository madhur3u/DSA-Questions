// https://leetcode.com/problems/design-circular-queue/

class MyCircularQueue {
public:
    
    // declaring global vector and variables for extremes and size initially 0
    vector<int> qu;
    int size = 0, front = 0, rear = 0;
    
    // this will make aur vector of size k for circular queue
    // initialise with all -1 as when queue empty and we parse front or rear it will output -1
    MyCircularQueue(int k) {
        qu.resize(k, -1);
    }
    
    // fn to add element in cqueue
    // if full return false, if empty both pointers at same point, inc size
    bool enQueue(int value) {
        if (isFull()) return false;
        
        if (isEmpty()){
            front = 0, rear = 0;
            qu[front] = value;
            size++;
            return true;
        }
        
        // the below condition will shift rear pointer to 1st index if rear + 1 is out of index
        rear = (rear + 1) % qu.size();
        qu[rear] = value;
        size++;
        return true;
    }
    
    // fn to delete element from front, false if empty
    // dec the size, initialise corrent front with -1 and shift front forward
    bool deQueue() {
        if (isEmpty()) return false;
        
        size--;
        qu[front] = -1;
        
        // the below condition will shift front pointer to 1st index if front + 1 is out of index
        front = (front + 1) % qu.size();
        return true;
    }
    
    int Front() {
        return qu[front];
    }
    int Rear() {
        return qu[rear];
    }
    bool isEmpty() {
        return size == 0;
    }
    bool isFull() {
        return size == qu.size();
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
