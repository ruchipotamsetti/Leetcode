// Brute Force: Reverse and compare, TC: O(n) + O(m) + O(m) = O(n), SC: O(n), where m is the length of the clean string, m<n

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string text = "";
        for(int i=0; i<n; i++){  //O(n)
            if(isalnum(s[i])){
                text += tolower(s[i]);
            }
        }
        string reverse = "";
        for(int i=text.length()-1; i>=0; i--){ //O(m)
            reverse += text[i];            
        }

        if(text == reverse){ //O(m)
            return true;
        }
        return false;
    }
};

// Solution 1: Create new clean string and then use two pointers approach, TC: O(n) + O(m) = O(n), SC: O(n)

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string text = "";
        for(int i=0; i<n; i++){ // O(n)
            if(isalnum(s[i])){
                text += tolower(s[i]);
            }
        }
        
        int i=0, j= text.length()-1;

        while(i<j){  // O(m)
            if(text[i] == text[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

// Solution 2: Optimized Space, TC: O(n), SC: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        
        int i=0, j= n-1;

        while(i<j){
            if(!isalnum(s[i])){
                i++;
            }
            else if(!isalnum(s[j])){
                j--;
            }
            else{
                if(tolower(s[i]) == tolower(s[j])){
                    i++;
                    j--;
                }
                else{
                    return false;
                }
            }
        }
        return true;
        
    }
};