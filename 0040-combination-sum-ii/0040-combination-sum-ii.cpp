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

        // take
        temp.push_back(candidates[ind]);
        findCombSum(ind + 1, candidates, target - candidates[ind], temp, ans);
        temp.pop_back();

        // skip
        while(ind+1<candidates.size() && candidates[ind+1]== candidates[ind] ){
            ind++;
        }
        findCombSum(ind + 1, candidates, target, temp, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        findCombSum(0, candidates, target, temp, ans);
        return ans;
    }
};