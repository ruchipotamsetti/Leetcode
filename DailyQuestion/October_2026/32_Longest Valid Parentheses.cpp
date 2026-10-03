class Solution {
public:
    int longestValidParentheses(string s) {
        int open = 0;
        int close = 0;
        int length=0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }

            if(open==close){
                length = max(length, open+close);
            }
            if(close>open){
                open=0;
                close=0;
            }
            
        }

        open=0;
        close=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='('){
                open++;
            }
            else{
                close++;
            }
            
            if(open==close){
                length = max(length, open+close);
            }
            if(open>close){
                open=0;
                close=0;
            }
            
        }

        return length;
    }
};