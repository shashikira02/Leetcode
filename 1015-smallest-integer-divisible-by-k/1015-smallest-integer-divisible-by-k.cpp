class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int curr =1, res =1;
        set<int>st;

        while(curr%k){
            if(st.count(curr))return -1;
            st.insert(curr);
            curr = 10*(curr%k)+1;
            res+=1;
        }
        return res;
    }
};