#include <iostream>

int main()
{
    int a, b;
    int n;
    std::cin >> a >> b >> n;
    if (a > (b + n - 1) / n)
        std::cout << "Yes";
    else
        std::cout << "No";
    return 0;
}