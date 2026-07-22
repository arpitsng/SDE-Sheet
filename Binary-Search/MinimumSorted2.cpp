//---------------engineered Approach--------------
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n =arr.size();
        
        int low = 0, high = n-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;

            while(low != high &&  low < n && arr[low] == arr[mid]){
                low++; 
                //continue;
            }

            while(low != high && high >= 0 && arr[high] == arr[mid]){
                high--; 
                //continue;
            }

            if(low <= high && arr[low] <= arr[mid]){ //left part sorted
                ans =min(ans, arr[low]);
                low = mid+1;
            }
            else if(low <= high && arr[high] > arr[mid]){                   //right part sorted
                ans = min(ans, arr[mid]);
                high = mid-1;
            }
           // else high--;
        }

        return ans;
    }
};