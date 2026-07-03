//------------optimal-----------
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n = arr.size();

        int sum = 0;
        vector<vector<int>> ans;
        vector<int> combo;
        solve(0, n, arr, combo, target, ans);

        return ans;
    }

    void solve(int i, int n, vector<int> &arr, vector<int> &combo, int k, vector<vector<int>> &ans){
        if(k == 0) {
            ans.push_back(combo);
            return;
        }

        if(i > n-1 || k < 0){
            return;
        }

        if(arr[i] <= k){
            combo.push_back(arr[i]);
            solve(i, n, arr, combo, k-arr[i], ans);
            combo.pop_back();
        }

        solve(i+1, n, arr, combo, k, ans);

    }
};