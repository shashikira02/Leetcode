class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {

        sort(folder.begin(),folder.end());
        set<string>st;
        vector<string>ans;

        for(int i =0;i<folder.size();i++){

            string s;
            bool flag = true;

            for(int j =0;j<folder[i].size();j++){
                if(folder[i][j] == '/'){
                    if(st.find(s) != st.end()){
                        flag = false;
                        break;
                    }
                }
                s += folder[i][j];
            }
            if(flag == true) st.insert(s);
        }
        for(auto i :st) ans.push_back(i);

        return ans;        
    }
};