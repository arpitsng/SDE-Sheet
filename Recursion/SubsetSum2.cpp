//------optimal-------------
    class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        int n = arr.size();
        vector<int> combo;
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        solve(0, n, arr, combo, ans);

        return ans;
    }

    void solve(int i, int n, vector<int> &arr, vector<int> &combo, vector<vector<int>> &ans){
        if(i == n){
            ans.push_back(combo);
            return ;
        }

        combo.push_back(arr[i]);
        solve(i+1, n, arr, combo, ans);

        combo.pop_back();
        while(i+1 < n && arr[i] == arr[i+1]) i++; //skip duplicates

        solve(i+1, n, arr, combo, ans);
    }
};