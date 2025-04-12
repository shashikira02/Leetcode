class Solution {
public:
    void combinations(int index, int target, const vector<int>& arr, vector<vector<int>>& ans, vector<int>& list) {
        if (target == 0) { 
            ans.push_back(list);
            return;
        }
        
        for (int i = index; i < arr.size(); i++) {
            if (i > index && arr[i] == arr[i - 1]) continue; // Skip duplicates
            if (arr[i] > target) break; // Prune the search

            list.push_back(arr[i]);
            combinations(i + 1, target - arr[i], arr, ans, list);
            list.pop_back(); // Backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates efficiently
        vector<vector<int>> ans;
        vector<int> list;
        combinations(0, target, candidates, ans, list);
        return ans;
    }
};
