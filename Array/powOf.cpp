///////---------optimal-----------------
//recursive
class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n;
        if(nn < 0) {
            x = 1/x;
            nn = -nn;
        }

        return (double)power(x, nn);
    }

    double power(double x, long long n){
        if(n == 0) return 1.0;
        if(n == 1) return x;
        
        //odd
        if((n & 1) == 1) return x * power(x, n-1); //ex: if 4^5 = 4 * 4^4
        
        //even
        return power(x*x, n/2);  //else if((n & 1) == 0) //ex: 4^4 = (4*4)^2

    }
};

//iterative
class Solution {    
public:
    double myPow(double x, int n) {
        long long nn = n;
        int ans = 1;

        if(nn < 0){
              x = 1/x;
              nn = -nn;  
        }

        while(nn > 0){
            if((nn % 2) == 0){
                x = x * x;
                nn /= 2;
            }

            else{
                ans = ans * x;
                nn--;
            }
        }
        return ans;
    }
};