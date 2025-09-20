// My solution:

class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        int n = strs.size();
        for(int i=0; i<n; i++){
            s += strs[i]+'?';
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>result;
        string word = "";
        for(int i=0; i<s.length(); i++){
            if(s[i]=='?'){
                result.push_back(word);
                word="";
            }
            else{
                word += s[i];
            }
            
        }
        return result;
    }
};

// Flawed because:
// Input: ["ab", "cd?ef"]
// Encoded: "ab?cd?ef?"
// Decoded: ["ab", "cd", "ef", ""]
// This is not equal to the original list, because "cd?ef" was broken apart.



// Solution 1:

class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        int n = strs.size();
        for(int i=0; i<n; i++){
            s += to_string(strs[i].size()) + "#" + strs[i]; //we need hash here because sometimes the length can be 2 digits like 10 but it will only consider 1 if it doesnt know when to stop
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>result;
        string word = "";
        int i=0;
        int n = s.length();
        while(i<n){
            string wlength = "";
            while(s[i] != '#'){
                wlength += s[i];
                i++;
            }
            int word_length = stoi(wlength);
            i++;
            word = s.substr(i, word_length);
            result.push_back(word);
            word="";
            i += word_length;
        }
        return result;
    }
};


