// Brute Force

class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m != n)
            return false;
        if(m==1 && n==1){
            return true;
        }
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        for(int i=0; i<m; i++){
            if(s[i] != t[i])
                return false;
        }

        return true;
    }
};

// Solution 1

class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.length();
        int n = t.length();
        if(m != n)
            return false;
        unordered_map<char, int>cnt;
        for(int i=0; i<m; i++){
            cnt[s[i]]++;
        }
        for(int i=0; i<n; i++){
            cnt[t[i]]--;
            if(cnt[t[i]] < 0)
                return false;
        }

        return true;
    }
};