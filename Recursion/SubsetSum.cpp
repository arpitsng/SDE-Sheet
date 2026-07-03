//memoized approach 
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (4001, -1));
        bool ans = solve(0, n, arr, sum, dp);
        
        return ans;
    }
    
    private:
        bool solve(int i, int n, vector<int> &arr, int k, vector<vector<int>> &dp){
            //base case 
            if(k == 0) return true;
            if(i == n) return false;
            
            if(dp[i][k] != -1) return dp[i][k];
            
            bool take = false;
            bool ntake = solve(i+1, n, arr, k, dp);
            
            if(arr[i] <= k){
                take = solve(i+1, n, arr, k - arr[i], dp);
            }
            
            return dp[i][k] = take || ntake;
        }
};