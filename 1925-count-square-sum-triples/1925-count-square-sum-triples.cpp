class Solution {
public:
    int countTriples(int n) {
        int count =0;

        for(int i=1;i<=n;i++){
            for(int j =2;j<=n;j++){
                int sq = sqrt(i*i+j*j);
                if(sq <=n && sq*sq == i*i+j*j )count++;
            }
        }
        return count;
    }
};