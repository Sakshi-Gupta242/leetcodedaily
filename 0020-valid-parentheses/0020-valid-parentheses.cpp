class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s){
            // opening bracket -> push
            if(c=='('||c=='['||c=='{'){
                st.push(c);
            }
            else{
                  // closing bracket aaya, lekin stack empty hai
                if(st.empty())
                return false;
           // bracket match nahi kar raha
        if((c==')'&&st.top()!='(')||(c==']'&&st.top()!='[')||(c=='}'&&st.top()!='{'))
        return false;
         // match ho gaya -> pop
        st.pop();
        }
    }
       // stack empty hai to valid
        return st.empty();    
    }
};