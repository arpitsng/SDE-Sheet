//---------------optimal-----------

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        
        //s1 : find the break point
        int bp = -1;
        for(int i=n-2; i>=0; i--){
            //we want i-1 > i
            if(arr[i] < arr[i+1]) {
                bp = i;
                break;
            }
        }

        //arr is sorted in descending so its next permumation will be the sorted one the smallest
        //or we can reverse it -- better complexity
        if(bp == -1) {
            reverse(arr.begin(), arr.end());
            return;
        }

        //s2: find the minimum that is greater than break point
        int mini = INT_MAX, minInd = -1;
        for(int i=bp; i<n; i++){
            if(arr[i] > arr[bp] && arr[i] < mini){
                mini = arr[i];
                minInd = i;
            }
        }   
        swap(arr[bp], arr[minInd]);


        //s3: sort the remaining part from bp+1 to end in ascending
        sort(arr.begin()+bp+1, arr.end());



    }
};