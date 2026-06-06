//-------------optimal ---------------------
class Solution {
public:
    long long inversionCount(vector<int> &arr) {
        int n = arr.size();
        return mergeSort(0, n - 1, arr);
    }

    long long mergeSort(int low, int high, vector<int> &arr) {
        // Base case: single element has 0 inversions
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;

        long long cnt = 0;

        // Count inversions in left half
        cnt += mergeSort(low, mid, arr);

        // Count inversions in right half
        cnt += mergeSort(mid + 1, high, arr);

        // Count cross inversions during merge
        cnt += merge(low, mid, high, arr);

        return cnt;
    }

    long long merge(int low, int mid, int high, vector<int> &arr) {
        vector<int> temp;

        int left = low;       // Left half: low -> mid
        int right = mid + 1; // Right half: mid+1 -> high

        long long cnt = 0;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } 
            
            else {
                temp.push_back(arr[right]);

                // arr[left] > arr[right]
                // All elements from left to mid are also > arr[right]
                cnt += (mid - left + 1);

                right++;
            }
        }

        // Remaining elements of left half
        while (left <= mid) {
            temp.push_back(arr[left++]);
        }

        // Remaining elements of right half
        while (right <= high) {
            temp.push_back(arr[right++]);
        }

        // Copy merged array back to original array
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }
};