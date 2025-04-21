class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        unordered_map<int,int>mp;
        int rabbits = 0;

        for(int rabbit : answers){
            if(mp.find(rabbit) != mp.end()){
                int x = mp[rabbit] ;
                x--;
                if(x == 0){
                    mp.erase(rabbit);
                }
                else{
                   mp[rabbit] = x;
                }
            }
            else{
                rabbits += rabbit;
                rabbits++;

                if(rabbit != 0) mp[rabbit] = rabbit;
            }
        }

        return rabbits;
    }
};