#include <iostream>
#include "chebyshev.h"

int main(int argc, char const *argv[]) {
    //ChebyshevPolynom<2>::print();
    std::cout << ChebyshevPolynom<4>::Px(2.0) << std::endl;
    //auto chebyPoints = ChebyshevPolynom<4>::getValuesAtPoints([](double x) { return 1.0 / (1.0 + std::pow(x, 2)); }, -5.0, 5.0);
    return EXIT_SUCCESS;
}
