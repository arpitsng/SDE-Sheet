//---------------optimal-----------
class Solution {
public:
    void rotate(vector<vector<int>>& grid) {
        int n = grid.size();

        //find transpose of matrix
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int temp = grid[i][j];
                grid[i][j] = grid[j][i];
                grid[j][i] = temp;
            }
        }

        //reverse each row
        for(int i=0; i<n; i++){
            reverse(grid[i].begin(), grid[i].end());
        }
    }
};