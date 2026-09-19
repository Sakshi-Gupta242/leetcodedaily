class Solution {
public:
// LPS array banane ka function
    void lpsfind(vector<int>& lps, string s) {

        int pre = 0;
        int suf = 1;

        while(suf < s.size()) {

            // Match
            if(s[pre] == s[suf]) {

                lps[suf] = pre + 1;

                pre++;
                suf++;
            }

            // Not matched
            else {

                // Koi prefix match nahi hua
                if(pre == 0) {

                    lps[suf] = 0;
                    suf++;
                }

                // Prefix ka kuch part already match hua tha
                else {

                    pre = lps[pre - 1];
                }
            }
        }
    }


    int strStr(string haystack, string needle) {

        // Step 1: LPS array
        vector<int> lps(needle.size(), 0);

        lpsfind(lps, needle);


        // Step 2: Search
        int first = 0;   // haystack pointer
        int second = 0;  // needle pointer

        while(first < haystack.size() &&
              second < needle.size()) {

            // Match
            if(haystack[first] == needle[second]) {

                first++;
                second++;
            }

            // Not matched
            else {

                // Kuch bhi match nahi hua
                if(second == 0) {

                    first++;
                }

                // Kuch characters already match ho chuke hain
                else {

                    second = lps[second - 1];
                }
            }
        }


        // Complete needle match ho gaya
        if(second == needle.size()) {

            return first - second;
        }

        // Needle nahi mila
        return -1;
    }
    int repeatedStringMatch(string a, string b) {
   
        int repeat = 1;
        string temp = a;

        while(temp.size()<b.size())
        {
            temp+=a;
            repeat++;          
        }
        //kmp pattern search
        if(strStr(temp,b)!= -1)
        return repeat;

        //Temp+a,kmp search
        temp+= a;

        if(strStr(temp,b)!= -1)
        return repeat+1;

        return -1;
        
    }
};