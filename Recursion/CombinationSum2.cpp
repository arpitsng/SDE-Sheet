//------------optimal---------------------
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        int n = arr.size();
        int k = target;

        vector<vector<int>> ans;
        vector<int> combo;
        sort(arr.begin(), arr.end());
        solve(0, n, arr, k, combo, ans);
        return ans;
    }

    void solve(int i, int n, vector<int> &arr, int k, vector<int> &combo, vector<vector<int>> &ans){
        if(k == 0){
            ans.push_back(combo);
            return;
        }

        if(i > n-1 || k < 0) return;

        if(arr[i] <= k){
            combo.push_back(arr[i]);
            solve(i+1, n, arr, k-arr[i], combo, ans);
            combo.pop_back();
        }

        while(i+1 < n && arr[i] == arr[i+1]) i++;

        solve(i+1, n, arr, k, combo, ans);
    }
};