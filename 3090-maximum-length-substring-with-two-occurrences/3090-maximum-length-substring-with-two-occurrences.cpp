class Solution {
public:
    int maximumLengthSubstring(string s) {
        
        int maxLen = 0;
        
        // Step 1: saare substrings
        for(int i = 0; i < s.size(); i++) {
            
            for(int j = i; j < s.size(); j++) {
                
                // frequency array for current substring
                int freq[26] = {0};
                bool valid = true;
                
                // Step 2: substring s[i...j] ki frequency check
                for(int k = i; k <= j; k++) {
                    
                    freq[s[k] - 'a']++;
                    
                    // kisi character ki frequency 2 se zyada
                    if(freq[s[k] - 'a'] > 2) {
                        valid = false;
                        break;
                    }
                }
                
                // Step 3: valid substring
                if(valid) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }
        
        // Step 4
        return maxLen;
    }
};