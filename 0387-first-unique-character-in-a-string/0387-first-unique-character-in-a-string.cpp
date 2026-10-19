//Pehle sabka count nikalo → phir left se right jao → jiska count 1 mile, uska index return karo.
class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};
    //har char ka count nikalo
        for (char c:s){
            freq[c- 'a']++;
        }
    //first unique char nikalo
         for(int i = 0;i <s.length();i++){
             if(freq[s[i]-'a']==1){
                return i;
             }
           }  
            return -1;      
      }
};