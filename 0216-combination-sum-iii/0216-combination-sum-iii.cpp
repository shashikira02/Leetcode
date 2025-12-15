class Solution {
public:
    void func(int i, int rem, int total, vector<int> temp,
              vector<vector<int>>& ans) {
        if (rem == 0 && total == 0) {
            ans.push_back((temp));
            return;
        }
        if (i > 9 || total < 0 || rem < 0)
            return;

        for (int ind = i; ind <= 9; ind++) {
            // take
            temp.push_back(ind);
            func(ind + 1, rem - 1, total - ind, temp, ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;

        func(1, k, n, temp, ans);
        return ans;
    }
};