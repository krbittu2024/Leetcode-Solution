class Solution {
public:
    const int MOD = 1e9 + 7;
    const int MAX = 100005;
    vector<long long> fact, invFact;

    long long modPow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1)
                res = res * base % MOD;
            base = base * base % MOD;
            exp /= 2;
        }
        return res;
    }

    void precomputeFactorials(int n) {
        fact.resize(n + 1);
        invFact.resize(n + 1);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        invFact[n] = modPow(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long long comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        precomputeFactorials(n); 
        long long c = comb(n - 1, k);
        long long powPart = modPow(m - 1, n - 1 - k);
        long long result = m * c % MOD * powPart % MOD;
        return result;
    }
};