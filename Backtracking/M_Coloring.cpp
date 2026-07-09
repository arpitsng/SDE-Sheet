//---------------------backtraking ---------------------
class Solution {
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
       vector<vector<int>> adj(v);
       
       for(auto e: edges){
           adj[e[0]].push_back(e[1]);
           adj[e[1]].push_back(e[0]);
       }
       
       vector<int> color(v, -1);
       return solve(0, v, m, adj, color);
        
        //return color[v-1] != -1;
    }
    
    bool solve(int node, int n, int m, vector<vector<int>> &adj, vector<int> &color){
        //base case
        if(node == n) {
            return true;
        }
        
        for(int i=0; i<m; i++){
            if(isSafe(i, node, color, adj)) {
                color[node] = i;
                if(solve(node+1, n, m, adj, color)){
                    return true;
                }
                
                else color[node] = -1;
            }
            
        }
        
        return false;
    }
    
    bool isSafe(int clr, int node, vector<int> &color, vector<vector<int>> &adj){
        for(auto nbr: adj[node]){
            if(color[nbr] == clr) return false;
        }
        return true;
    }
};