class Solution {
public:
    void func(int ind, int sum,int n,vector<vector<int>>& ans,vector<int>&list,int k){
        if(sum == n && k ==0){
            ans.push_back(list);
            return;
        }
        if(ind>n)return;
        for(int i =ind;i<=9;i++){
            if(i>n)break;
            list.push_back(i);
            func(i+1,sum+i,n,ans,list,k-1);
            list.pop_back();
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> list;
        func(1,0,n,ans,list,k);
        return ans;
    }
};