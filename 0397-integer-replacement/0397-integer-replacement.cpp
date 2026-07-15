class Solution {
public:
    int f(long long n) {

        if (n == 1) return 0;

        int even = INT_MAX;
        int odd = INT_MAX;

        if (n % 2 == 0) {
            even = 1 + f(n / 2);
        }

        if (n % 2 != 0) {
            odd = 1 + min(f(n - 1), f(n + 1));
        }

        return min(even, odd);
    }

    int integerReplacement(int n) {
        return f((long long)n);
    }
};