class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> nums; // calculates nums ex n = 4=> nums = {1,2,3,4};
        for(int i=1;i<n;i++){
            fact = fact*i; // calculate the fact ex: n =4 => (n-1)! = 6
            nums.push_back(i); 
        }
        nums.push_back(n);
        string ans = "";
        k = k-1; // 0 based
        while(true){
            ans = ans + to_string(nums[k/fact]);// Append the chosen number to the ans string
            nums.erase(nums.begin() + k/fact);//and remove it from nums
            if(nums.size() == 0)break;
            k = k%fact; // the position within the current block.
            fact = fact/nums.size();// Reduce the block size
        }
        return ans;
    }
};