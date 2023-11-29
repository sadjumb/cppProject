#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main(int argc, char* argv[])
{
    size_t n;
    std::cin >> n;
    long int tmp = 0;
    std::vector<long int> arr(n);
    std::vector<long int> a;
    std::vector<long int> b{ 0 };
    long int s = 0;

    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> arr[i];
        tmp += arr[i];
        a.push_back(arr[i] * i - s);
        s += arr[i];
    }

    s = 0;
    for (int i = n - 1, j = 1; i > 0; --i, ++j)
    {
        s += j * arr[i] - arr[i - 1] * j;
        b.push_back(s);
    }

    for (size_t i = 0; i < a.size() && i < b.size(); ++i)
    {
        std::cout << a[i] + b[b.size() - 1 - i] << ' ';
    }
    return 0;
}