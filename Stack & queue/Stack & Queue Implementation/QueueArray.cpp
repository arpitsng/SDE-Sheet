//----------------code---------------------------
class myQueue {

  public:
    int front = 0, rear = 0;
    int cnt = 0;  //number of element
    vector<int> arr;
    
    myQueue(int n) {
        arr.resize(n);
    }

    bool isEmpty() {
        return cnt == 0;
    }

    bool isFull() {
        return cnt == arr.size();
    }

    void enqueue(int x) {
        int n = arr.size();
        if(!isFull()){
            arr[rear] = x;
            rear = (rear + 1) % n;
            cnt++;
        }
    }

    void dequeue() {
        int n = arr.size();
        if(!isEmpty()){
            front = (front + 1)%n;
            cnt--;
        }
    }

    int getFront() {
       if(!isEmpty()){
           return arr[front];
       }
       
       return -1;
    }

    int getRear() {
        int n = arr.size();
        if(!isEmpty()){
            return arr[(rear - 1 + n) % n];
        }
        
        return -1;
    }
};