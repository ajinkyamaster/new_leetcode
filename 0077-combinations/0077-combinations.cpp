class Solution {
public:
    void f(int n, int k, vector<int> &ans, vector<vector<int>>&res){
        if(k<=0){
            res.push_back(ans);
            return;
        }
        if(n<=0) return;

        ans.push_back(n);
        f(n-1, k-1,ans, res); //choose n
        ans.pop_back();
        f(n-1, k, ans, res); // not choose n
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
         vector<vector<int>> res;
         f(n, k, ans, res);

         return res;
    }
};