class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int first = 0;
        int second = 0;
        int maxfreq = 0;
        int len = 0;

        while(second<s.size()){
            count[s[second]-'A']++;
            maxfreq = max(maxfreq, count[s[second]-'A']);

            int changes = (second - first +1)-maxfreq;

            while(changes>k){
                count[s[first]-'A']--;
                first++;
                changes = (second - first +1)-maxfreq;
            }
                len = max(len,second - first+1);

                second++;
        }
        return len;
    }
};