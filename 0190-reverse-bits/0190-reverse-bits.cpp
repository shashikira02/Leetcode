class Solution {
public:
    bool func(int i , unsigned int n){ // checking if ith bit is 1 or not

        if(((1<<(i-1)) & n) != 0) return true;
        return false;
    }
    uint32_t reverseBits(uint32_t n) {
        unsigned int ans = 0;
        
        for(int i = 1;i<=32;i++){
            
            if(func(i,n)){
                
                ans = 1<<(32 -i) | ans;
            }
        }

        return ans;
    }
};