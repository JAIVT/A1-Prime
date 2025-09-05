#include "prime.hpp"

static inline void bump(long long* p) {
    if (p) (*p)++;
}

bool isPrimeHalf(int n, long long* modOps) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if ((n & 1) == 0) return false;

    for (int i = 3; i <= n / 2; i += 2) {
        bump(modOps);
        if (n % i == 0) return false;
    }
    return true;
}

bool isPrimeSqrt(int n, long long* modOps) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if ((n & 1) == 0) return false;

    for (int i = 3; 1LL * i * i <= n; i += 2) {
        bump(modOps);
        if (n % i == 0) return false;
    }
    return true;
}

long long countModOps(PrimeFn isPrime, int lo, int hi) {
    long long total = 0;
    for (int n = lo; n <= hi; ++n) {
        long long ops = 0;
        isPrime(n, &ops);
        if (ops == 0) {
            ops = 1;
        }
        total += ops;
    }
    return total;
}
