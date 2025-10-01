class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty= 0;
        while(numBottles >=numExchange){
            int rem = numBottles / numExchange;
            
            empty += numExchange*rem;
            numBottles -=  numExchange*rem;

            numBottles +=rem;
        }
        return empty+numBottles;
    }
};