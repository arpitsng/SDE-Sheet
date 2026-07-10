//dp + recursion 
class Solution {
public:
    bool wordBreak(string s, vector<string>& dict) {
        int n = s.size();
        unordered_set<string> hash(dict.begin(), dict.end());
        vector<int> dp(n, -1);
        return solve(0, s, hash, dp);
    }

    bool solve(int ind, string &s, unordered_set<string> &hash, vector<int> &dp){
        //base case
        if(ind == s.size()){
            return true;
        }

        if(dp[ind] != -1) return dp[ind];

        string word = "";
        for(int i=ind; i<s.size(); i++){
            word += s[i];
            if(hash.count(word)){
                if(solve(i+1, s, hash, dp)){
                    return dp[ind] = true;
                }
            }
        }
        return dp[ind] = false;
    }
};