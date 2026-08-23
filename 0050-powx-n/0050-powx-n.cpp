class Solution {
public:
    double myPow(double x, int n) {
        long exp = n;

        if (exp < 0){
            x = 1/x;
            exp = -exp;
        }
        double ans  = 1;
        while(exp>0){
        if(exp%2 != 0)//odd power like 2^5 =2*2^4
        ans *= x;
    x *= x;
    exp /=2;
    }
      return ans;
    }
};