//------------code---------------------
class myStack {
  public:
    vector<int> stk;
    int top = -1;
    
    myStack(int n) {
        stk.resize(n);
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == stk.size() -1;
    }

    void push(int x) {
        if(!isFull()){
            top++;
            stk[top] = x;
        }
    }

    void pop() {
        if(top != -1){
            // stk[top] = -1;
            top--;
        }
    }

    int peek() {
        if(!isEmpty()){
            return stk[top];
        }
        
        return -1;
    }
};