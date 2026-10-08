// My approach:
//Time Complexity: O(n) where n is the length of the string s. We iterate through the string once, performing constant time operations for each character.
//Space Complexity: O(n) for the stack used to keep track of the parentheses. 
// In the worst case, the stack can grow to the size of the input string if all characters are opening parentheses.

class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string result="";
        stack<char>st;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                if(!st.empty()){
                    result += s[i];
                }
                st.push('(');
            }
            else{
                if(st.size()>1){
                    result += s[i];
                }
                st.pop();
            }
        }

        return result;
    }
};

//My approach 2:
//Time Complexity: O(n) where n is the length of the string s. 
// We iterate through the string once, performing constant time operations for each character.
//Space Complexity: O(1) as we are using a counter to keep track of the balance of parentheses instead of a stack, 
// which uses constant space.   
class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string result="";
        int openCnt = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='('){
                if(openCnt != 0){
                    result += s[i];
                }
                openCnt++;
            }
            else{
                if(openCnt>1){
                    result += s[i];
                }
                openCnt--;
            }
        }

        return result;
    }
};

//Time Complexity: O(n) where n is the length of the string s.
// We iterate through the string once, performing constant time operations for each character.
//Space Complexity: O(1) as we are using a counter to keep track of the balance of parentheses instead of a stack,
// which uses constant space.
class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string result="";
        int openCnt = 0;
        for(char ch:s){
            if(ch =='('){
                if(openCnt != 0){
                    result += ch;
                }
                openCnt++;
            }
            else{
                if(openCnt>1){
                    result += ch;
                }
                openCnt--;
            }
        }

        return result;
    }
};