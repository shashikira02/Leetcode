class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res = 0;
        sort(intervals.begin(), intervals.end(), [](auto a, auto b) {
            if (a[1] == b[1])
                return a[0] > b[0];
            return a[1] < b[1];
        });

        int p1 = -1, p2 = -1;

        for (auto interval : intervals) {
            int left = interval[0], right = interval[1];

            if (p2 < left) {
                res += 2;
                p1 = right - 1;
                p2 = right;
            } else if (p1 < left) {
                res += 1;
                if (p2 == right)
                    p1 = right - 1;
                else {
                    p1 = p2;
                    p2 = right;
                }
            }
        }
        return res;
    }
};