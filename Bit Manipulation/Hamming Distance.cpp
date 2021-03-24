// Problem can also be "Find number of bits to change, to convert x to y"

class Solution {
public:
    int hammingDistance(int x, int y) {
        int a=x^y;
        int cnt=0;
        while(a > 0){
            a = a & (a-1);
            cnt++;
        }
        return cnt;
    }
};
