#include <iostream>
#include <vector>
#include <cmath>

int main()
{
    int n, b;

    std::cin >> n;
    std::vector<int> v(n);

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }
    std::cin >> b;
    int tmp = 0;
    for (size_t i = 0; i < n; ++i)
    {
        if (fabs(v[tmp] - b) > fabs(v[i] - b))
            tmp = i;
    }
    std::cout << v[tmp];
    return 0;
}