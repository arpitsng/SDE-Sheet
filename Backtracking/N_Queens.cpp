//------------backtracking---------------------
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.')); //board
        vector<vector<string>> ans;
        
        int row = 0;
        solve(row, grid, ans);

        return ans;
    }

    void solve(int row, vector<string> &grid, vector<vector<string>> &ans){
        //base case
        if(row == grid.size()){
            ans.push_back(grid);
            return ;
        }

        for(int col=0; col<grid.size(); col++){
            if(isSafe(row, col, grid)){
                grid[row][col] = 'Q';
                solve(row+1, grid, ans);
                grid[row][col] = '.';
            }
        }

    }

        bool isSafe(int row, int col, vector<string> &grid){
            //col check
            for(int i=0; i<=row; i++){
                if(grid[i][col] == 'Q') return false;
            }

            //left upper dia
            int i=row, j = col;
            while(i >= 0 && j >= 0){
                if(grid[i][j] == 'Q') return false;
                i--; j--;
            }

            //right upper dia
            i=row, j = col;
            while(i >= 0 && j < grid.size()){
                if(grid[i][j] == 'Q') return false;
                i--; j++;
            }

            return true;
            
        }
    
};