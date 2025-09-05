#include <iostream>
#include "prime.hpp"

int main() {
    constexpr int LO = 2, HI = 10000;

    long long halfOps = countModOps(&isPrimeHalf, LO, HI);
    long long sqrtOps = countModOps(&isPrimeSqrt, LO, HI);

    std::cout << "Half method operations: " << halfOps << "\n";
    std::cout << "Sqrt method operations: " << sqrtOps << "\n";

    double ratio = (sqrtOps == 0) ? 0.0 : static_cast<double>(halfOps) / static_cast<double>(sqrtOps);
    std::cout << "Ratio (Half/Sqrt): " << ratio << "\n";

    return 0;
}
