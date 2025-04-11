class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        vector<int>prefixMax(n,0);

        prefixMax[0] = height[0];
        for(int i =1;i<n;i++)prefixMax[i] = max(prefixMax[i-1], height[i]); 
        int water =0;
        int suffixMax =0;
        for(int i =n-1;i>=0;i--){         
            suffixMax = max(suffixMax, height[i]);
            water += max(0, min(prefixMax[i], suffixMax) - height[i]);
        }
        return water;
    }
};