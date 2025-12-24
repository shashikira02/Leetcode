class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int sum =0;
        for(int i =0;i<n;i++){
            sum += apple[i];
        }

        sort(capacity.rbegin(), capacity.rend());
        int needed =0;
        while(sum>0){
            sum -= capacity[needed];
            needed += 1;
        }
        return needed;
    }
};