#include <iostream>

int main(int argc, char* argv[])
{
    size_t t;
    std::cin >> t;
    for (size_t i = 0; i < t; ++i)
    {
        unsigned long long int a, b, n;
        std::cin >> n >> a >> b;
        if (a == 1 || !(n % a) || !(n % b))
        {
            std::cout << "YES\n";
            continue;
        }
        unsigned long long int groups = n / a;
        if (n % a <= groups * (b - a))
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    }
    return 0;
}