#include <iostream>

int main()
{
    int a, b;
    std::cin >> a >> b;
    int n, m;
    std::cin >> n >> m;
    int min1 = a * (n - 1) + n;
    int max1 = a * (n + 1) + n;
    int min2 = b * (m - 1) + m;
    int max2 = b * (m + 1) + m;
    if (std::min(max1, max2) < std::max(min1, min2))
        std::cout << -1;
    else
        std::cout << std::max(min1, min2) << ' ' << std::min(max1, max2);
    return 0;
}