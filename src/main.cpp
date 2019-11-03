#include <iostream>
#include "chebyshev.h"

int main(int argc, char const *argv[]) {
    auto chebyPoints = ChebyshevPolynom<11>::getValuesAtPoints([](double x) { return 1.0 / (1.0 + std::pow(x, 2)); }, -5.0, 5.0);
    for(auto e : chebyPoints) {
        std::cout << e << std::endl;
    }
    return EXIT_SUCCESS;
}
