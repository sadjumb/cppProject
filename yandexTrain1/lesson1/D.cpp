#include <iostream>
#include <vector>

int main()
{
    int res = 0;
    int a, b, c;
    std::cin >> a >> b;
    if (std::cin >> c)
        if (b > a && b > c)
            ++res;
    while (std::cin >> a)
    {
        std::swap(a, b);
        std::swap(b, c);
        if (b > a && b > c)
            ++res;
    }
    std::cout << res;
    return 0;
}