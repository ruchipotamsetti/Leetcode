// My solution:
// Time Complexity: O(N*log(num2)) where N is the number of integers between num1 and num2. 
// We are iterating through each integer in the range and for each integer, we are checking its digits which takes O(log(num2)) time.
// Space Complexity: O(1) as we are using only a constant amount of extra space for the waviness variable and the variables used to check the digits of the number.

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        if(num1<100 && num2<100)
            return 0;

        if(num1<100){
            while(num1<100){
                num1++;
            }
        }
        int waviness = 0;
        int i=num1;
        while(i<=num2){
            int value = i;
            int prev = value%10;
            value=value/10;
            int curr = value%10;
            value = value/10;
            int next = value%10;
            while(value>0){
                if(curr>prev && curr>next){
                    waviness++;
                }
                else if(curr<prev && curr<next){
                    waviness++;
                }
                value=value/10;
                prev = curr;
                curr = next;
                next = value % 10;
            }
            i++;
        }
        
        return waviness;
    }
};