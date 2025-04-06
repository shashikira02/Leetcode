class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(); int li=-1;
        if(n==1) return nums;
        sort(nums.begin(),nums.end());
        vector<int> temp(n,1), hash(n); int m=INT_MIN;
        for(int i=0;i<n;i++){
            hash[i]=i;
           for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && temp[i]<1+temp[j]){
                    temp[i]=1+temp[j];
                    hash[i]=j;
                }
                if(m<temp[i]){
                    m=temp[i];
                    li=i;
                }
           }
            }
            int ind=m-1;
            vector<int> p(m,0);
            while(hash[li]!=li){
                p[ind--]=nums[li];
                li=hash[li];
            }
           p[ind]=nums[li];
        return p;
    }
};