//---------------optimal--------------------
class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();   
        if(n == 0) return 0;
        sort(arr.begin(), arr.end());
        int maxi = 0;
        int len = 0;
        for(int i=0; i<n-1; i++){
            if(arr[i] == arr[i+1]) continue;

            else if(arr[i] + 1 == arr[i+1]) {
                len++;
                maxi = max(maxi, len+1);
            }

            else{
                len = 0;
            }
        }

        if(maxi == 0) return 1;

        return maxi;
    }
};