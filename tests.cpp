#include <cassert>
#include "prime.hpp"

static void check_basic() {
    long long ops = 0;
    assert(!isPrimeHalf(0, &ops));   assert(ops == 0);
    ops = 0; assert(!isPrimeSqrt(1, &ops));   assert(ops == 0);

    ops = 0; assert(isPrimeHalf(2, &ops));    assert(ops == 0);
    ops = 0; assert(isPrimeSqrt(2, &ops));    assert(ops == 0);

    ops = 0; assert(isPrimeHalf(3, &ops));    assert(ops == 0);
    ops = 0; assert(isPrimeSqrt(3, &ops));    assert(ops == 0);

    ops = 0; assert(!isPrimeHalf(10, &ops));  assert(ops == 0);
    ops = 0; assert(!isPrimeSqrt(10, &ops));  assert(ops == 0);
}

static void check_primes_and_composites() {
    int primes[] = {5,7,11,13,17,19,23,29,31};
    for (int p : primes) { assert(isPrimeHalf(p, nullptr)); assert(isPrimeSqrt(p, nullptr)); }
    int comps[] = {9,15,21,25,27,33,35,39,49};
    for (int c : comps) { assert(!isPrimeHalf(c, nullptr)); assert(!isPrimeSqrt(c, nullptr)); }
}

static void check_mod_counts_individual() {
    long long ops = 0;
    (void)isPrimeSqrt(9, &ops);  assert(ops == 1);
    ops = 0; (void)isPrimeHalf(25, &ops); assert(ops == 2);
    ops = 0; (void)isPrimeSqrt(49, &ops); assert(ops == 3);
}

static void check_counts_over_ranges() {
    long long half = countModOps(&isPrimeHalf, 2, 200);
    long long srt  = countModOps(&isPrimeSqrt, 2, 200);
    assert(srt <= half);
}

int main() {
    check_basic();
    check_primes_and_composites();
    check_mod_counts_individual();
    check_counts_over_ranges();
}
