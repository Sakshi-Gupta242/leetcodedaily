class Solution {
public:
    int smallestNumber(int n, int t) {
     while(true){
        int prod=1;
        int x=n,d;
        while(x>0){
            d=x%10;
            prod *= d;
            x= x/10;
        }
        if(prod%t ==0){
            return n;
        }
        n=n+1;
     }   
    }
};