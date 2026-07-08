//-----------------backtracking optimized--------------------
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        int row = 0;
        solve(board);
    }

    bool  solve(vector<vector<char>>& board){
   
        for(int row=0; row<9; row++)
            for(int col=0; col<9; col++){
                if(board[row][col] == '.'){
                    for(char i='1'; i<='9'; i++){
                        if(isSafe(row, col, i, board)){
                            board[row][col] = i;
                            bool furtherPossible = solve(board);
                            if(furtherPossible) return true;
                            else board[row][col] = '.'; //backtrack
                        }
                    }

                    return false; //if we cant place any of 9 vals then its impossible
                }

            }

            return true;
    }

    bool isSafe(int row, int col, char num, vector<vector<char>>& board){
        
        for(int i=0; i<9; i++){
            //row check
            if(board[row][i] == num) return false;

            //col checkt
            if(board[i][col] == num) return false;

            ////3x3 box check
            if(board[3* (row/3) + i/3][3* (col/3) + i%3] == num){
                return false;
            }
        }

        return true;
    }
};