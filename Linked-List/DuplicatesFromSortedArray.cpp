//-----------optimal---------------------
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();

        int ind = 0;
        int i = 0;

        while(i < n){
            if(arr[ind] != arr[i]){
                swap(arr[i], arr[ind+1]);
                ind++;
            }
            i++;

        }

        return ind+1;

    }
};