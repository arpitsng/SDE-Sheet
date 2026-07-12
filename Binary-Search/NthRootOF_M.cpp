class Solution {
  public:
    int nthRoot(int n, int m) {
          // n-th root of 0 is 0
    if (m == 0) return 0;

    // If n is 1, the answer 
    // is m itself
    if (n == 1) return m;

    // binary search to find 
    // the integer root
    int low = 1, high = m;
    while (low <= high) {
        int mid = (low + high) / 2;

        // compute mid^n and compare it with m
        int val = power(mid, n, m);

        if (val == m)
            return mid;  
        else if (val < m)
            low = mid + 1;  
        else
            high = mid - 1; 
    }

    return -1;
        
    }
    
    int power(int base, int expo, int limit) {
    int result = 1;
    for (int i = 0; i < expo; i++) {
        result *= base;
        
        if (result > limit)  
            return result;
    }
    return result;
}
};