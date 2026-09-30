class Solution {
public:
    bool isAnagram(string s, string t) {
        //LENGTH DIFFERENT HAI TO ANAGRAM NHI HO SAKTA
        if(s.size() != t.size()){
            return false;
        }
        //26 letters ki frequency
        int count[26] = {0};

        // s ke liye +1,t ke liye -1
        for(int i =0;i< s.size();i++){
            count[s[i]-'a']++;
            count[t[i]-'a']--;
        }
        
        // sab frequency 0 honi chahiye
        for(int i = 0;i<26;i++){
            if(count[i] != 0){
                return false;
            }
        }
        return true;      
    }
};