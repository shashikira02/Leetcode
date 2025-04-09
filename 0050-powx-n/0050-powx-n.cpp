class Solution {
public:
    double myPow(double x, long n) {
        int sign = 1;
        double ans =1.0;
        if(n<0){
            n = -1*n;
            sign = -1;
        }
        while(n>0){
            if(n%2 == 1){
                ans = ans*x;
                n = n-1;
            }
            else{
                x = x*x;
                n = n/2;
            }
        }
        if(sign ==-1)return 1.0/ans;

        return ans;
    }
};