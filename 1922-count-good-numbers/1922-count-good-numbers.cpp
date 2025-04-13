# define mod 1000000007;
class Solution {
public:
    long long powe(long long x, long long y){
        if(y ==0)return 1;
        long long ans = powe(x,y/2);
        ans *=ans;
        ans%=mod;
        if(y%2) ans *=x;
        ans %= mod;
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long odd = n/2;
        long long even = n/2+n%2;

        return (powe(5,even)*powe(4,odd))%mod;
    }
};