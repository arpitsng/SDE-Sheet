//-----brute force approach-----------
class Solution {
public:
    string getPermutation(int n, int k) {
        string s = "";

        for(int i=1; i<=n; i++){
            s += (i + '0');
        }

        vector<string> ans;
        solve(0, s, ans);
        sort(ans.begin(), ans.end());

        return ans[k-1];
    }

    void solve(int ind, string part, vector<string> &ans){
        if(ind == part.length()){
            ans.push_back(part);
            return ;
        }

        for(int i=ind; i<part.length(); i++){
            swap(part[i], part[ind]);
            solve(ind+1, part, ans);
            swap(part[i], part[ind]);
        }
    }
};