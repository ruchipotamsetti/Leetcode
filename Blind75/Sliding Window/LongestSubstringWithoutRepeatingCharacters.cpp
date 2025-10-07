// Brute Force: TC: O(n∗m), SC: O(m), Where n is the length of the string and m is the total number of unique characters in the string.

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int longest = 0;
        unordered_set<char>check;

        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check.find(s[j]) != check.end()){
                    break;
                }
                check.insert(s[j]);
            }

            longest = max(longest, (int)check.size());
            check.clear();
        }

        return longest;

    }
};

// Sliding Window Solution: TC: O(n), SC: O(m), using sliding window + hashset

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int longest = 0;
        unordered_set<char>check;
        int l=0;
        for(int r=0; r<n; r++){
            while(check.find(s[r]) != check.end()){
                check.erase(s[l]);
                l++;
            }
            check.insert(s[r]);
            longest = max(longest, r-l+1);
        }

        return longest;

    }
};

// Sliding Window Solution Optimal:  TC: O(n), SC: O(m), using hashmap instead of hashset

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int longest = 0;
        unordered_map<char, int>check;
        int l=0;
        for(int r=0; r<n; r++){
            if(check.find(s[r]) != check.end()){
                l = max(check[s[r]]+1, l);
            }
            check[s[r]] = r;
            longest = max(longest, r-l+1);
        }

        return longest;
    }
};