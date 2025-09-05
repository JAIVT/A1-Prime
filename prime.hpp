#ifndef PRIME_HPP
#define PRIME_HPP

using PrimeFn = bool(*)(int, long long*);

bool isPrimeHalf(int n, long long* modOps=nullptr);
bool isPrimeSqrt(int n, long long* modOps=nullptr);
long long countModOps(PrimeFn isPrime, int lo, int hi);

#endif
