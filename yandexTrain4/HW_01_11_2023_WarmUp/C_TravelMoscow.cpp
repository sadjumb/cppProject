#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

int main()
{
    long double x1, y1, x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    std::cout << std::setprecision(17);
    if (sqrt(x2 * x2 + y2 * y2) < sqrt(x1 * x1 + y1 * y1))
    {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    long double at1 = std::atan2(y1, x1) + M_PI;
    long double at2 = std::atan2(y2, x2) + M_PI;
    long double circl1 = fabs(at1 - at2) * sqrt(x1 * x1 + y1 * y1) + fabs(sqrt(x2 * x2 + y2 * y2) - sqrt(x1 * x1 + y1 * y1));
    long double circl2 = fabs(at1 + at2) * sqrt(x1 * x1 + y1 * y1) + fabs(sqrt(x2 * x2 + y2 * y2) - sqrt(x1 * x1 + y1 * y1));
    long double r = sqrt(x2 * x2 + y2 * y2) + sqrt(x1 * x1 + y1 * y1);

    if (r < circl1 && r < circl2)
        std::cout << r;
    else if (circl1 > circl2)
        std::cout << circl2;
    else
        std::cout << circl1;
    return 0;
}