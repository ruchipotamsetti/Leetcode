// Sliding window with Array of size 26: TC: O(N*26), SC:O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, maxCharCnt=0;
        int n=s.length();
        vector<int>cnt(26,0);
        int result = 0;
        for(int r=0; r<n;r++){
            cnt[s[r]-'A']++;
            int maxChar=0;
            for(int i=0; i<26; i++){
                maxChar = max(maxChar, cnt[i]);
            }
            while((r-l+1)-maxChar > k){
                cnt[s[l]-'A']--;
                l++;
            }
            result = max(result, r-l+1);
        }

        return result;
    }
};

//Sliding Window Optimal: TC: O(n) because now there now check for char with highest frquency, SC:O(26)

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, maxCharCnt=0;
        int n=s.length();
        vector<int>cnt(26,0);
        int result = 0;
        int maxCnt = 0;
        for(int r=0; r<n;r++){
            cnt[s[r]-'A']++;
            maxCnt = max(maxCnt, cnt[s[r]-'A']);
            while((r-l+1)-maxCnt > k){
                cnt[s[l]-'A']--;
                l++;
            }
            result = max(result, r-l+1);
        }

        return result;
    }
};