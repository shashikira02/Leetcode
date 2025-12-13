class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd =INT_MIN;
        // int prod =1;

        for(int i=0;i<n;i++){
            int prod =1;
            for(int j =i;j<n;j++){
                prod *= nums[j];
                maxProd = max(prod, maxProd);
            }
        }
        return maxProd;
    }
};