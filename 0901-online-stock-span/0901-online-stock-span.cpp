class StockSpanner {
public:
    stack<pair<int, int>> st; // Stack to store {price, index} pairs
    int ind = -1;             // Tracks the current index of the price

    // Constructor to initialize variables
    StockSpanner() {
        ind = -1;                 // Set the index to -1 for the initial state
        while (!st.empty()) st.pop(); // Clear the stack if it's not empty
    }
    
    int next(int price) {
        ind = ind + 1; // Increment the index to represent the current day
        
        // Remove all elements from stack with price <= current price
        while (!st.empty() && st.top().first <= price) {
            st.pop(); // Remove smaller or equal prices as they're irrelevant
        }

        // Calculate the span
        // If stack is empty, all previous days' prices are smaller
        // Else, calculate span as the difference between indices
        int ans = ind - (st.empty() ? -1 : st.top().second);

        // Push the current price and its index into the stack
        st.push({price, ind});

        return ans; // Return the calculated span
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
