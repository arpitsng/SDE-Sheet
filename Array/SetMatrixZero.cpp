//-----------------------------------------optimal
class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        //we'll use first row and col as a marker -- and then well traverse the grid from bottom to up then we mark the cell
        //if there's zero in first col then well mark that col also zero but from bottom to top 

        bool ZeroInFirstCol = false;
        for(int i=0; i<m; i++){
            if(grid[i][0] == 0) ZeroInFirstCol = true;
            for(int j=1; j<n; j++){ //not acessing the first col
                if(grid[i][j] == 0){ //mark the first row and col 0
                    grid[0][j] = 0;
                    grid[i][0] = 0; 
                }
            }
        }

        //now traverse from bottom -- if we find zero in its correspoding first row or col then mark that cell as 0
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=1; j--){ //dont access the first col
                if(grid[i][0] == 0 || grid[0][j] == 0){
                    grid[i][j] = 0;
                }
            }

            if(ZeroInFirstCol){ //mark the first col zero -- will not affect as we are moving in bottom up fashion
                grid[i][0] = 0;
            }
        }


    }
};

//-------------------------------------b`rute force
class Solution {
public:
    void setZeroes(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        unordered_set<int> seenRow, seenCol;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    if(!seenRow.count(i)){
                        seenRow.insert(i);
                    }
                    if(!seenCol.count(j)){
                        seenCol.insert(j);
                    }
                }

                else continue;
            }
        }

        for(auto i : seenRow){
            setRowZero(i, grid);
        }

        for(auto j: seenCol){
            setColZero(j, grid);
        }
    }

    void setRowZero(int row, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();

        for(int i=0; i<n; i++){
            grid[row][i] = 0;
        }
    }

    void setColZero(int col, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();

        for(int i=0; i<m; i++){
            grid[i][col] = 0;
        }
    }
};