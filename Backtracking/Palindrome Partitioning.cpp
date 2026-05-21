//Time Complexity: O(n*2^n) where n is the length of the string. 
//We are generating all possible partitions of the string, which can be exponential in number, and for each partition, we are checking if it is a palindrome, which takes O(n) time.
//Space Complexity: O(n) for the recursion stack and the space used to store the current partition. 
//The result vector can also take up to O(n*2^n) space in the worst case, if all partitions are palindromic.  

class Solution {
public:
    vector<vector<string>>result;
    vector<vector<string>> partition(string s) {
        vector<string>partition;
        findParts(0, 0, s, partition);
        return result;
    }

    void findParts(int i, int j, string& s, vector<string>& partition){

        if(i>=s.size()){
            if(i==j){
                result.push_back(partition);
            }
            return;
        }


        if(isPalindrome(j, i, s)){
            partition.push_back(s.substr(j,i-j+1));
            findParts(i+1, i+1, s, partition);
            partition.pop_back();
        }

        findParts(i+1, j, s, partition);

    }

    bool isPalindrome(int l, int r, string& s){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};


//Time Complexity: O(n*2^n) where n is the length of the string. 
//We only add palindrome pieces, we explore all valid ways to partition the string, which can be exponential in number, and for each partition, we are checking if it is a palindrome, which takes O(n) time.
//Space Complexity: O(n) for the recursion stack and the space used to store the current partition. 
//The result vector can also take up to O(n*2^n) space in the worst case, if all partitions are palindromic.
class Solution {
public:
    vector<vector<string>>result;
    vector<vector<string>> partition(string s) {
        vector<string>partition;
        findParts(0, s, partition);
        return result;
    }

    void findParts(int i, string& s, vector<string>& partition){

        if(i>=s.size()){
            result.push_back(partition);
            return;
        }        

        for(int j=i; j<s.size(); j++){
            if(isPalindrome(i, j, s)){
                partition.push_back(s.substr(i,j-i+1));
                findParts(j+1, s, partition);
                partition.pop_back();
            }
        }
    }

    bool isPalindrome(int l, int r, string& s){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }

        return true;
    }
};