class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        if(st.empty()) {
            st.push(val);
            mini = val;
        } else {
            if(val < mini) {
                st.push(2LL * val - mini); 
                mini = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if(st.empty()) return;
        long long ele = st.top();
        st.pop();
        if(ele < mini) {
            mini = 2LL * mini - ele; 
        }
    }

    int top() {
        if(st.empty()) return -1;
        long long ele = st.top();
        if(ele < mini) return mini;
        return ele;
    }

    int getMin() {
        return mini;
    }
};
