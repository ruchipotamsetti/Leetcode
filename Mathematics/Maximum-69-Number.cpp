class Solution {
public:
    int maximum69Number (int num) {
        int lastDigit = num % 10;
        vector<int>digits; //this vector stores all digits of num
        digits.insert(digits.begin(), lastDigit); 
        
        while(num / 10 != 0)
        {
            num = num / 10;
            lastDigit = num % 10;  // last digit of reduced num
            digits.insert(digits.begin(), lastDigit);  // inserting each digit at beginning
        }
        for(int i = 0; i < digits.size(); i++)
        {
            if(digits[i] == 6)
            {
                digits[i] = 9; // replacing 6 by 9 for the first occurence
                break;
            }
        }
        
        int max = digits[0];
        for(int i=1; i < digits.size(); i++)
        {
            max = max * 10 + digits[i]; //computing max num from the vector
        }
        return max;
    }
};
