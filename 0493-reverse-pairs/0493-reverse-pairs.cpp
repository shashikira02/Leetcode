class Solution {
public:
    int count =0;
    void merge(vector<int>& nums, int left,int middle, int right){
        vector<int>temp;
        int low = left;
        int high =  middle+1;

        while(low <= middle && high <= right){
            if(nums[low] <= nums[high]){
                temp.push_back(nums[low]);
                low++;
            }
            else {
                temp.push_back(nums[high]);
                high++;
            }
        } 

        while(low <= middle){
            temp.push_back(nums[low]);
            low++;
        }
        while(high <= right){
            temp.push_back(nums[high]);
            high++;
        }

        for(int i = left; i<= right;i++){

            nums[i] = temp[i-left];
        }
    }

    void countPairs(vector<int>& nums, int left,int middle, int right){
        int point = middle+1;
        for(int i =left;i<=middle;i++){
            while(point <= right && ((long long)nums[i] > (long long)2*nums[point]))point++;
            count += (point - (middle+1));
        }
    }
    void mergeSort(vector<int>& nums, int low, int high){
        if(low>=high)return ;
        int mid = low + (high-low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        countPairs(nums, low, mid, high);
        merge(nums,low,mid,high);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return count;
    }
};