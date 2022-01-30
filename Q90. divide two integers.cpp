class Solution {
public:
    //     // brute force
    //     // tle
    //     int divide(int dividend, int divisor) {

    //         int quotent = 0, sign = 1;
    //         if(divisor<0 || dividend<0) sign = -1;
    //         if(divisor<0 && dividend<0) sign = 1;

    //         divisor = abs(divisor);
    //         dividend = abs(dividend);

    //         int n = divisor;
    //         while(divisor <= dividend) {
    //             divisor += n;
    //             quotent++;
    //         }

    //         return quotent*sign;
    //     }

        // bit manupulation

    int divide(int dividend, int divisor) {
        if (dividend == divisor)
            return 1;
        bool isPositive = (dividend < 0 == divisor < 0);    // if both are of same sign, answer is positive
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while (a >= b) {  // while dividend is greater than or equal to divisor
            short q = 0;
            while (a > (b << (q + 1)))
                q++;
            ans += (1 << q);  // add the power of 2 found to the answer
            a = a - (b << q);  // reduce the dividend by divisor * power of 2 found
        }
        if (ans == (1 << 31) and isPositive)   // if ans cannot be stored in signed int
            return INT_MAX;
        return isPositive ? ans : -ans;
    }
};