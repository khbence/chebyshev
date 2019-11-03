#include <array>
#include <cmath>

template<unsigned degree>
class ChebyshevPolynom {
    constexpr static auto initParameters() {
        std::array<int, degree/2 + 1> param{};
        decltype(param) old{1}; //f(x) = 1
        param[0] = 1; //f(x) = x
        if(!degree) { return param; }
        for(unsigned i = 0; i < degree-1; ++i) {
            auto tmp = param;
            for(unsigned j = 0; j < param.size(); ++j) {
                param[j] *= 2;
                if(j) { param[j] -= old[j-1]; }
            }
            old = tmp;
        }
        return param;
    }

    constexpr static auto initPoints() {
        std::array<double, degree> ps{};
        for(unsigned j = 0; j < degree; ++j) {
            ps[j] = std::cos(((2*static_cast<double>(j) - 1)*M_PI) / (2*static_cast<double>(degree)));
        }
        return ps;
    }

    constexpr static auto parameters = initParameters();
    constexpr static auto points = initPoints();

    template<std::size_t... N>
    constexpr static double polynom(double x, std::index_sequence<N...>) {
        return ((parameters[N] * std::pow(x, degree - (2*N))) + ...);
    }

    constexpr static double Px(double x) {
        return polynom(x, std::make_index_sequence<parameters.size()>());
    }

    //TODO multiply with fx, but first just return the polynom
public:
    template<typename function>
    constexpr static auto getValuesAtPoints(function fx, double a, double b) {
        std::array<double, degree> values{};
        for(unsigned i = 0; i < values.size(); ++i) {
            values[i] = Px(points[i]);
        }
        return values;
    }
};