#include <iostream>

int main()
{
    int n, k, m;
    int inv = 0;

    std::cin >> n >> k >> m;

    int tmp = (n % k) + (n / k) * (k % m);
    size_t res = n / k * (k / m);
    while (tmp / k)
    {
        res += tmp / k * (k / m);
        tmp = (tmp % k) + (tmp / k) * (k % m);
        //std::cout << tmp << ' ';
    }
    std::cout << res;
    return 0;
}