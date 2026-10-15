// My solution:
// Time Complexity: O(num) where num is the number of digits in the resulting number.
// We iterate through the number of digits and perform constant time operations for each digit.
// Space Complexity: O(num) as we are using a string to store the resulting number.

class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string result = "";

        int nines = sum/9;
        int rem = sum%9;

        if(num<=nines && rem>0)
            return result;

        for(int i=0;i<num;i++){
            if(nines>0){
                result+="9";
                nines--;
            }
            else if(rem){
                result+=to_string(rem);
                rem=0;
            }
            else{
                result+="0";
            }
        }

        return result;
    }
};