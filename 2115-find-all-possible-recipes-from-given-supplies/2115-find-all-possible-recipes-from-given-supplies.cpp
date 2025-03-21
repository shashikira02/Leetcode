class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> Supplies(supplies.begin(), supplies.end());

        queue<int> q;
        for(int i =0;i< recipes.size(); i++){
            q.push(i);
        }
        vector<string> created;
        int last = -1;

        while(static_cast<int>(Supplies.size()) > last){
            last = Supplies.size();
            int queueSize = q.size();

            while( queueSize-- > 0){
                int i = q.front();
                q.pop();
                bool satisfy = true;

                for(string & ingredient: ingredients[i]){
                    if(!Supplies.count(ingredient)){
                        satisfy = false;
                        break;
                    }
                }

                if(!satisfy){
                    q.push(i);
                }else{
                    Supplies.insert(recipes[i]);
                    created.push_back(recipes[i]);
                }
            }
        }
        return created;
    }
};