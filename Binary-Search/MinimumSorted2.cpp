//--------------------ideal Approach-------------------
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int l = 0, h = n-1;

        while(l < h){
            int mid = l + (h-l)/2;

            if(nums[mid] > nums[h]) l = mid + 1;
            else if(nums[mid] < nums[h]) h = mid;

            else{
                h--; //we are doing l++ and h--  both coz we need to return the minimum value -- thats nums[l]
                //so we can duduce it form the left
            }
        }

        return nums[l];
    }
};


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