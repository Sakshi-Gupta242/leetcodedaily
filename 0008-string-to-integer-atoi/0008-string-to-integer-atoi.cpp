class Solution {
public:
    int myAtoi(string s) {
        int i =0,sign =1;
        long long ans =0;

        while(i<s.size()&&s[i]==' ')
        i++;

        if(s[i]=='-'){
            sign = -1;
            i++;
        }
        else if(s[i]=='+'){
            sign =1;
            i++;
        }

        while(i<s.size() && isdigit(s[i])){
            ans = ans*10+(s[i]-'0');

            if(ans>INT_MAX)
            return sign == 1?INT_MAX:INT_MIN;
            i++;
        }
        return sign *ans;
    }
};