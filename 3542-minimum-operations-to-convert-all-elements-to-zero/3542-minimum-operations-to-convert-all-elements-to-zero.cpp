class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        int size =0, ans=0;

        for(int num: nums){
            if(num ==0){
                ans += size;
                size=0;
                continue;
            }
            while(size >0 && arr[size-1]>num){
                size--;
                ans++;
            }
            if(size == 0 || arr[size-1] < num){
                arr[size] = num;
                size++;
            }
        }
        ans += size;
        return ans;
    }
};