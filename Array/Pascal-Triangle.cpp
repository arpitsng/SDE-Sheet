//Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n = numRows;
        vector<vector<int>> ans(n); //give size here coz .. memory is unallocated and were trying to resize the unallocated memory below that'll give RTE

        for(int i=0;i<n; i++){
            ans[i].resize(i+1, 1); //initially all one

            for(int j=1; j<i; j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }

};