#include <iostream>

int main()
{
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0)
    {
        std::cout << "MANY SOLUTIONS";
    }
    else if (c < 0 || (a == 0 && b != c * c))
        std::cout << "NO SOLUTION";
    else
        std::cout << (c * c - b) / a;
    return 0;
}