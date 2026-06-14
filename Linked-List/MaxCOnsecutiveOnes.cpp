//--------------------------optimal---------------------
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& arr) {
        int n = arr.size();

        int len = 0, curr = 0;
        for(int i=0; i<n; i++){
            if(arr[i] == 1){
                curr++;
                len = max(len, curr);
                continue;
            }

            else curr = 0;
        }

        return len;

    }
};