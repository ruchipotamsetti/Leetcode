// My approach and code:
// Time Complexity: O(n) where n is the length of the string s.
// We iterate through the string once, performing constant time operations for each character.
// Space Complexity: O(1) as we are using a counter to keep track of the balance of parentheses instead of a stack,
// which uses constant space.
class Solution {
public:
    int minInsertions(string s) {

        int rightPending = 0;
        int rightNeeded = 0;
        int leftNeeded = 0;

        for(char ch:s){
            if(ch=='('){
                if(rightPending%2==1){
                    rightNeeded++;
                    rightPending--;
                }
                rightPending+=2;
            }
            else{
                if(rightPending==0){
                    leftNeeded++;
                    rightPending+=2;
                }
                rightPending--;
            }
        }
        return rightPending+rightNeeded+leftNeeded;
    }
};

//Better Variable names and comments:
// Time Complexity: O(n) where n is the length of the string s.
// We iterate through the string once, performing constant time operations for each character.
// Space Complexity: O(1) as we are using a counter to keep track of the balance of parentheses instead of a stack,
// which uses constant space.

class Solution {
public:
    int minInsertions(string s) {
        int pendingClose = 0;   // ')' still owed to the '(' seen so far
        int insertedClose = 0;  // ')' we had to insert
        int insertedOpen = 0;   // '(' we had to insert

        for (char ch : s) {
            if (ch == '(') {
                if (pendingClose % 2 == 1) {
                    // The previous '(' got only one ')', so insert the second now.
                    insertedClose++;
                    pendingClose--;
                }
                pendingClose += 2;
            } else {
                if (pendingClose == 0) {
                    // No '(' to match, so insert one. It now owes 2 ')', and this one pays 1.
                    insertedOpen++;
                    pendingClose += 2;
                }
                pendingClose--;
            }
        }
        // Whatever is still owed at the end must be inserted too.
        return insertedOpen + insertedClose + pendingClose;
    }
};