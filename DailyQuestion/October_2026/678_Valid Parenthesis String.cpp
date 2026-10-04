//Time Complexity: O(n)
//Space Complexity: O(1)

class Solution {
public:
    bool checkValidString(string s) {
        int open = 0;
        int close = 0;
        int star = 0;
        int n = s.length();
        for(int i=0; i<n; i++){  
            if(s[i] == '('){
                open++;
            }
            else if(s[i] == ')'){
                close++;
            }
            else{
                star++;
            }
            if(close>open+star){
                return false;
            }
        }

        open=0;
        close=0;
        star=0;
        for(int i=n-1; i>=0; i--){
                
            if(s[i] == '('){
                open++;
            }
            else if(s[i] == ')'){
                close++;
            }
            else{
                star++;
            }

            if(close+star<open){
                return false;
            }
        }

        return true;
    }
};