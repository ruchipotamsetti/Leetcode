class Solution {
public:
    bool isValid(string s) {
        stack<char>check;
        int n = s.length();
        int i=0;
        while(i<n){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                check.push(s[i]);
            }
            else{
                if(!check.empty()){
                    char open = check.top();
                    check.pop();
                    if((open == '(' && s[i]==')') || (open == '[' && s[i]==']') || (open == '{' && s[i]=='}')){
                        i++;
                        continue;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
            i++;
        }

        return check.empty();

    }
};