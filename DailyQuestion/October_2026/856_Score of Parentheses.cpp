//Time Complexity: O(n)
//Space Complexity: O(n)

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        stack<int>st;
        st.push(0);
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(0);
            }
            else{
                int top = st.top();
                st.pop();
                if(top == 0){
                    int v = st.top();
                    st.pop();
                    st.push(v+1);
                }
                else{
                    int v = st.top();
                    st.pop();
                    st.push(v + (top*2));
                }
            }
            
        }
        return st.top();
    }
};


//Better Approach
//Time Complexity: O(n)
//Space Complexity: O(1)

class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int result = 0;
        int depth = 0;
        char prev = s[0];
        depth++;
        for(int i=1; i<n; i++){
            if(s[i] == '('){
                depth++;
            }
            else{
                depth--;
                if(prev=='('){
                    result += 1<<depth;
                }
            }   
            prev = s[i];         
        }
        return result;
    }
};