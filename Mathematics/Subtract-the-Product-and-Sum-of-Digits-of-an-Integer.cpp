class Solution {
public:
    int subtractProductAndSum(int n) {
        int digit = n % 10; //gives last digit of n
        int sum = digit;
        int product = digit;
        while(n / 10 != 0)
        {
            n = n / 10;
            digit = n % 10; //gives last digit of n, after n is reduced
            sum = sum + digit;
            product = product * digit;
        }
        return product - sum;
    }
};
