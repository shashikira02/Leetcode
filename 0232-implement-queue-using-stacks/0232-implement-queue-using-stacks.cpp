
class MyQueue {
    stack<int> inp, out;
public:
    MyQueue() {}

    void push(int x) {
        inp.push(x);
    }

    int pop() {
        if (out.empty()) {
            while (!inp.empty()) {
                out.push(inp.top());
                inp.pop();
            }
        }
        if (out.empty()) return -1; 
        int temp = out.top();
        out.pop();
        return temp;
    }

    int peek() {
        if (out.empty()) {
            while (!inp.empty()) {
                out.push(inp.top());
                inp.pop();
            }
        }
        if (out.empty()) return -1;
        return out.top();
    }

    bool empty() {
        return inp.empty() && out.empty();
    }
};
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */