class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp; // To store the frequency of each element

        // Min-heap to store k most frequent elements
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Step 1: Count the frequencies of elements
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++; // Increment the count for each occurrence
        }

        // Step 2: Add frequency-element pairs to the heap
        for (auto it : mp) {
            pq.push({it.second, it.first}); // Push (frequency, element) into the min-heap
            if (pq.size() > k) pq.pop();   // If size exceeds k, remove the least frequent element
        }

        vector<int> ans;

        // Step 3: Extract elements from the min-heap
        while (!pq.empty()) {
            ans.push_back(pq.top().second); // Store the element (second in pair)
            pq.pop();                       // Remove the top of the heap
        }

        return ans; // Return the k most frequent elements
    }
};
