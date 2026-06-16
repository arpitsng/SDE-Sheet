class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        int knapsack = 0;
        double ans = 0.0;
        
        vector<pair<double, int>> mpp; //ratio, weight
        for(int i=0; i<n; i++){
            mpp.push_back({(double)val[i]/wt[i], wt[i]});
        }
        
        sort(mpp.begin(), mpp.end(), greater<pair<double,int>>());
        
        for(auto it: mpp){
            if(it.second + knapsack <= capacity){
                ans += it.first * it.second;
                knapsack += it.second;
            }
            
            else{
                int rem = capacity - knapsack;
                ans += rem * it.first;
                break;
            }
            
            
        }
            return ans;
        
    }
};
