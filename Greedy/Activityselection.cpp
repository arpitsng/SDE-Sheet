class Solution {
  public:
    int activitySelection(vector<int> &st, vector<int> &end) {
        int n = st.size();
        vector<pair<int, int>> mpp;
        for(int i=0; i<n; i++){
            mpp.push_back({st[i], end[i]});
        }
        
        sort(mpp.begin(), mpp.end(), [](const pair<int, int> &a, const pair<int, int> &b){
            if(a.second == b.second) return a.first < b.first;
            
            return a.second < b.second;
        });
        
        int cnt = 1;
        int prev = mpp[0].second;
        for(int i=1; i<n; i++){
            auto curr = mpp[i];
            if(curr.first > prev) {
                cnt++;
                prev = curr.second;
            }
        }
        
        return cnt;
    }
};