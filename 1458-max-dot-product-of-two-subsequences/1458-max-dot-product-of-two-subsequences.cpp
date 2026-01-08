class Solution {
public:
    int maxi = -1e9;
    int func(int i, int j, vector<int>& a, vector<int>& b){
        if(i == a.size() || j == b.size())return maxi;

        long long take = a[i]*b[j];
        long long cont = a[i]* b[j] + func(i+1, j+1, a, b);
        long long skipA = func(i+1, j, a, b);
        long long skipB = func(i, j+1, a, b);

        return max({(int)take, (int)cont , (int)skipA, (int)skipB});
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();

        return func(0,0,nums1, nums2);

    }
};