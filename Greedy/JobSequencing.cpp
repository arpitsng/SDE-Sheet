class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int cnt = 0;
        int i=0, j=0, ans = 1;
        while(i<n){
            if(arr[i] <= dep[j]){
                i++;
                cnt++;
            }
            else{
                j++;
                cnt--;
            }
            
            ans = max(ans, cnt);
        }
        
        return ans;
    }
};
