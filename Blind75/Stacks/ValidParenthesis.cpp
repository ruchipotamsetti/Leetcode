// Brute Force:

//notes:

// size_t → an unsigned integer type used for sizes and indices (like int, but always non-negative).
// string::npos → a constant in C++ representing “not found” (its value is typically -1, but for size_t it means the largest possible number).
// So we initialize pos to mean “position not found yet.”

// if ((pos = s.find("()")) != string::npos) { ---> This line is doing three things at once
// 1. Searches the string s for the substring "()".
// Returns the index (position) of the first occurrence if found.
// Returns string::npos if not found.
// 2. Assigns that position to the variable pos.
// 3. Checks whether a match was found (i.e., pos is not equal to string::npos).

// erase(index, count) removes count characters from s, starting at position index.

class Solution {
public:
    bool isValid(string s) {
        size_t pos = string::npos; //the variable pos is storing the result of s.find("()"), and since .find() returns a size_t, it makes sense to match the type.

        while(true){
            if((pos = s.find("()")) != string::npos){
                s.erase(pos,2);
                continue;
            }
            if((pos = s.find("{}")) != string::npos){
                s.erase(pos,2);
                continue;
            }
            if((pos = s.find("[]")) != string::npos){
                s.erase(pos,2);
                continue;
            }
            break;
        }

        return s.empty();
    }
};



//My code: TC:O(n), SC:O(n)

class Solution {
public:
    bool isValid(string s) {
        int n= s.length();
        int i=0;
        stack<char>st;
        unordered_map<char, char>mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';
        while(i<n){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){ //using mp.count(s[i]) would be better here
                st.push(s[i]);
            }
            else{
                if(!st.empty()){
                    char top = st.top();
                    if(mp[top] == s[i]){
                        st.pop();
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

        if(st.empty()){ //here instead we can just return st.empty()
            return true;
        }
        else{
            return false;
        }
    }
};

// Simpler code: TC:O(n), SC:O(n)

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (closeToOpen.count(c)) {
                if (!stack.empty() && stack.top() == closeToOpen[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};