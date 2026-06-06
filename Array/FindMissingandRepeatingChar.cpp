//----------------optimal-----------------
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        //s - sn = x-y
        //s2 - s2n 
        
        long long sn = n * (n+1)/2;
        long long s2n = n * (n+1) * (2*n + 1)/6;
        
        long long s = 0, s2 = 0;
        
        for(auto x : arr){
            s += (long long)x;
            s2 += (long long)x * (long long)x;
        }
        
        long long diff1 = s - sn;
        long long diff2 = s2 - s2n;  
        
        long long val1 = diff1; //x - y
        long long val2 = diff2/val1;  //x + y
        
        long long x = (val1 + val2)/2;
        long long y = x - val1;
        
        return {(int)x, (int)y};
        
        
    }
};