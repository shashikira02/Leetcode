class Solution {
public:
    void combinatons(int ind, vector<int>& candidates, int target,
                        vector<vector<int>>& ans, vector<int>& temp) {
        if (ind == candidates.size()) {
            if (target == 0)
                ans.push_back(temp);
            return;
        }

        if (candidates[ind] <= target) {
            temp.push_back(candidates[ind]);
            combinatons(ind, candidates, target - candidates[ind], ans,
                           temp);
            temp.pop_back();
        }
        combinatons(ind + 1, candidates, target, ans, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinatons(0, candidates, target, ans, temp);
        return ans;
    }
};