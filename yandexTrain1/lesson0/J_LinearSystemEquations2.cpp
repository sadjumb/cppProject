#include <iostream>
#include <iomanip>

int main()
{
    double a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    if (a == 0 && b == 0 && c == 0 && d == 0)
    {
        if (e == 0 && f == 0)
            std::cout << 5;
        else
            std::cout << 0;
    }
    else if (a != 0 && b != 0 && c != 0 && d != 0)
    {
        if (d * a - c * b == 0)
        {
            if (a * f - c * e != 0)
            {
                std::cout << 0;
            }
            else
            {
                std::cout << 1 << ' ' << std::setprecision(6) << -a / b << ' ' << e / b;
            }
        }
        else
        {
            std::cout << 2 << ' ' << std::setprecision(6)
                << (e * (d * a - c * b) - b * (f * a - c * e)) / (a * (d * a - c * b)) << ' '
                << (f * a - c * e) / (d * a - c * b);
        }
    }
    else if (a == 0 && b == 0 && c == 0)
    {
        if (e == 0)
            std::cout << 0;
        else
            std::cout << 4 << ' ' << std::setprecision(6) << f / d;
    }
    else if (a == 0 && b == 0 && d == 0)
    {
        if (e == 0)
            std::cout << 0;
        else
            std::cout << 3 << ' ' << std::setprecision(6) << f / c;
    }
    else if (a == 0 && d == 0 && c == 0)
    {
        if (f == 0)
            std::cout << 0;
        else
            std::cout << 4 << ' ' << std::setprecision(6) << e / b;
    }
    else if (b == 0 && d == 0 && c == 0)
    {
        if (f == 0)
            std::cout << 0;
        else
            std::cout << 3 << ' ' << std::setprecision(6) << e / a;
    }
    else if (a == 0 && c == 0)
    {
        if (b * f - e * d == 0)
            std::cout << 4 << ' ' << std::setprecision(6) << e / b;
        else
            std::cout << 0;
    }
    else if (b == 0 && d == 0)
    {
        if (a * f - c * e == 0)
            std::cout << 3 << ' ' << std::setprecision(6) << e / a;
        else
            std::cout << 0;
    }
    else if (a == 0 && b == 0)
    {
        if (e == 0)
            std::cout << 0;
        else
            std::cout << 1 << ' ' << std::setprecision(6) << c / d << ' ' << f / d;
    }
    else if (c == 0 && d == 0)
    {
        if (f == 0)
            std::cout << 0;
        else
            std::cout << 1 << ' ' << std::setprecision(6) << a / b << ' ' << e / b;
    }
    else if (a == 0)
    {
        std::cout << std::setprecision(6) << 2 << ' ' << (f - (d * e) / b) / c << ' ' << e / b;
    }
    else if (b == 0)
    {
        std::cout << std::setprecision(6) << 2 << ' ' << e / a << ' ' << (f - c * e / a) / d;
    }
    else if (c == 0)
    {
        std::cout << std::setprecision(6) << 2 << ' ' << (e - (b * f) / d) / a << ' ' << f / d;
    }
    else if (d == 0)
    {
        std::cout << std::setprecision(6) << 2 << ' ' << f / c << ' ' << (e - a * f / c) / b;
    }
    return 0;
}