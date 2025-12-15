    class Solution {
    public:
        int rob(vector<int>& nums) {
            int n =nums.size();
            if( n == 1)
                return nums[0];
            if (n == 2)
                return max(nums[0], nums[1]);

            // using first Element removing last
            vector<int> inclFirst(nums.begin(), nums.end() - 1);

            // using last Element removing first
            vector<int> inclLast(nums.begin() + 1, nums.end());

            vector<int> dp1(inclFirst.size() + 1, 0);

            vector<int> dp2(inclLast.size() + 1, 0);

            dp1[0]=inclFirst[0];
            dp2[0]=inclLast[0];

            dp1[1]=max(inclFirst[0], inclFirst[1]);
            dp2[1]=max(inclLast[0], inclLast[1]);

            for(int i =2;i<n-1;i++){
                dp1[i] =
                    max(dp1[i - 2] + inclFirst[i], dp1[i - 1]);
                dp2[i] =
                    max(dp2[i - 2] + inclLast[i], dp2[i - 1]);
            }

            return max(dp1[inclFirst.size()-1], dp2[inclFirst.size()-1]);
        }
    };