class Solution {
public:
     int maxArea(vector<int>& height) {
    int ans = 0;
    int l = 0, r = height.size() - 1;

    while (l < r) {
        int area = (r - l) * min(height[l], height[r]);
        ans = max(area, ans);

        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return ans;
   

    //     int ans = 0, n = height.size();

    //     for(int i =0;i<n;i++){
    //         for(int j = i+1;j<n;j++){
    //             int area = (j-i)*min(height[i],height[j]);
    //             ans = max(area,ans);
    //         }
    //     }
    //     return ans;

    // int s=0,e= height.size()-1;
    // int area;
    // int water = 0;

    // while(s<e){

    //     area = min(height[s],height[e])*(e-s);

    //     if (area>water) water = area;

    //     if(min(height[s],height[e])==height[s])  s++;

    //     else e--;
    // }
    // return water;
}
}
;