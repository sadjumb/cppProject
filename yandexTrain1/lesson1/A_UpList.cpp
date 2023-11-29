#include <iostream>

int main()
{
    int a, b;
    std::cin >> a;
    while (std::cin >> b)
    {
        if (b <= a)
        {
            std::cout << "NO";
            return 0;
        }
        std::swap(a, b);
    }
    std::cout << "YES";
    return 0;
}