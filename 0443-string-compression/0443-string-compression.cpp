class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int idx = 0;

        for(int i =0;i<n;i++){
            char ch = chars[i];
            int count =0;

            while(i<n && chars[i]== ch){
                count++;i++; // jab tak same char aa raha h hum count ko plus karte jayenge
            }
             //a
            if(count == 1){
                chars[idx++]=ch;
            }
                else{
                    chars[idx++] = ch;
                    //to_string int ko string me change karne me help karta h

                    string str = to_string(count);
                    for(char dig : str){
                        chars[idx++]= dig;
                    }
                }
                i--;
            }
            chars.resize(idx);
            return idx;
    }
};