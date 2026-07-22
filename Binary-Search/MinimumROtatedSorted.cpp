//--------intended Approach---------
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int r = n-1, l = 0;

        while(l < r){
            int mid = l + (r - l)/2;

            if(nums[r] < nums[mid]){
                l = mid +1;
            }

            else{
                r = mid;
            }
        }

        return nums[l];
    }
};


//-----------engineering appraoch-------------
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n =arr.size();
        
        int low = 0, high = n-1;
        int ans = INT_MAX;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(arr[low] <= arr[mid]){ //left part sorted
                ans =min(ans, arr[low]);
                low = mid+1;
            }
            else{                   //right part sorted
                ans = min(ans, arr[mid]);
                high = mid-1;
            }
        }

        return ans;
    }
};