class Solution {
public:
    void findCombSum(int ind, vector<int>& candidates, int target,
                     vector<int>& temp, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0 || ind == candidates.size())
            return;

        for (int i = ind; i < candidates.size(); i++) {
            if(candidates[i] >target)break;
            temp.push_back(candidates[i]) ;
            
            // take  & skip happens when the i > ind
            findCombSum(i, candidates, target - candidates[i], temp, ans);

            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());

        findCombSum(0, candidates, target, temp, ans);

        return ans;
    }
};