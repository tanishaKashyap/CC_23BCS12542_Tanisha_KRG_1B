class Solution {
public:
    static const int MOD = 1e9 + 7;
    long long gcd(long long a, long long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int nthMagicalNumber(int n, int a, int b) {
        long long l = min(a, b);
        long long r = (long long)n * min(a, b);
        long long lcm = (a / gcd(a, b)) * b;

        while (l < r) {
            long long mid = l + (r - l) / 2;
            long long cnt = mid / a + mid / b - mid / lcm;
            if (cnt < n)
                l = mid + 1;
            else
                r = mid;
        }
        return l % MOD;
    }
};
