class Solution {
public:
    int numSquares(int n) {
        // Lagrange's Four Square theorem
        while(n % 4 == 0) {
            n /= 4;
        }
        if(n % 8 == 7) {
            return 4;
        }
        int a = 0;
        while ((a * a) <= n) {
            int b = sqrt((n - a * a));
            if(a * a + b * b == n) {
                if(a != 0 && b != 0) {
                    return 2;
                } else{
                    return 1;
                }
            }
            a++;
        }
        return 3;
    }
};