//----------------recursion and backtracking--------------------
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int ind = 0;
        vector<int> part = nums;
        vector<vector<int>> ans;
        solve(ind, part, ans);
        return ans;
    }

    void solve(int ind, vector<int> &part, vector<vector<int>> &ans){
        if(ind == part.size()){
            ans.push_back(part);
            return;
        }

        for(int i=ind; i<part.size(); i++){
            swap(part[i], part[ind]);
            solve(ind+1, part, ans);
            swap(part[i], part[ind]);
        }
    }
};