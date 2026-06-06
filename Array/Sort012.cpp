//- --------------better --- -------- brute force = sort the array
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();

        int z = 0, o = 0, t = 0;

        for(auto x: arr){
            if(x == 0) z++;
            else if(x == 1) o++;
            else t++;
        }

        int i = 0;
        while(z || o || t){
            if(z) {
                arr[i++] = 0;
                z--;
                continue;
            }

            if(o) {
                arr[i++] = 1;
                o--;
                continue;
            }

            if(t) {
                arr[i++] = 2;
                t--;
                continue;
            }
        }

    }
};


//-----------------optimal -- dutch national flag algorithm
class Solution {
public:
    void sortColors(vector<int>& arr) {
        int n = arr.size();

        int low = 0, mid = 0, high = n-1;

        while(mid <= high){
            if(arr[mid] == 0){
                swap(arr[low], arr[mid]);
                mid++;
                low++;
            }

            else if(arr[mid] == 1){
                mid++;
            }

            else { //arr[i] == 2
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};