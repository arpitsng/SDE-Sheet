class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        int low = 0, high = n-1;

        while(low <= high){
            int mid = low + (high - low)/2;

            if(mid & 1){
                if(arr[mid-1] == arr[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }

            else{
                if((mid+1 < n) && arr[mid+1] == arr[mid]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }

        return arr[low];
    }
};