//---------------recursion--------------------
class Solution {
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0) return {};
        vector<vector<bool>> vis(n, vector<bool> (n, false));
        string path = "";
        vector<string> ans;
        solve(0,0, path, ans, maze, vis);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
    
    void solve(int i, int j, string &path, vector<string> &ans, vector<vector<int>>& maze, vector<vector<bool>>& vis){
        int n = maze.size();
        //base case
        if(i == n-1 && j == n-1) {
            ans.push_back(path);
            return;
        }
        
        vis[i][j] = true;
        
        //down
        if(i+1 < n && !vis[i+1][j] && maze[i+1][j]){
            path += 'D';
            solve(i+1, j, path, ans, maze, vis);
            path.pop_back();
        }
        
        //up
        if(i-1 >= 0 && !vis[i-1][j] && maze[i-1][j]){
            path += 'U';
            solve(i-1, j, path, ans, maze, vis);
            path.pop_back();
        }
        
        //right
        if(j+1 < n && !vis[i][j+1] && maze[i][j+1]){
            path += 'R';
            solve(i, j+1, path, ans, maze, vis);
            path.pop_back();
        }
        
        //left
        if(j-1 >= 0 && !vis[i][j-1] && maze[i][j-1]){
            path += 'L';
            solve(i, j-1, path, ans, maze, vis);
            path.pop_back();
        }
        
        vis[i][j] = false;
    }
};