class Solution {
public:
    int countBits(int N, long long A[]) {
        const int MOD = 1000000007;
        long long ans = 0;
        for (int bit = 0; bit < 31; bit++) {
            long long cnt1 = 0;

            for (int i = 0; i < N; i++) {
                if (A[i] & (1LL << bit))
                    cnt1++;
            }
            long long cnt0 = N - cnt1;
            ans = (ans + 2LL * cnt1 * cnt0) % MOD;
        }

        return ans;
    }
};