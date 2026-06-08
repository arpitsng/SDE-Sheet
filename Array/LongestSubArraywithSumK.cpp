//-----------optimal-----------------
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
       int n = arr.size();
       
       unordered_map<int, int> mp; //{sum, i}
       int maxi = 0;
       int prefsum = 0;
       
       for(int i=0; i<n; i++){
           prefsum += arr[i];
           
           if(prefsum == k){
               maxi = i+1;
           }
           
           else if(mp.count(prefsum - k)){
               maxi = max(maxi, i - mp[prefsum-k]);
           }
           
           if(!mp.count(prefsum)){
               mp[prefsum] = i;
           }
       }
       
       return maxi;
        
    }
};