#include <iostream>
#include <vector>
#include <cmath>

bool equalSubstr(const std::vector<long long int>& h, const std::vector<long long int>& x, int l, int s1, int s2, long long int p)
{
    return (h[s1 + l - 1] + h[s2 - 1] * x[l]) % p == (h[s2 + l - 1] + h[s1 - 1] * x[l]) % p;
}

int main()
{
    long long int x_ = 257;
    long long int p = pow(10, 9) + 7;

    std::string str;
    std::cin >> str;
    str = ' ' + str;

    std::vector<long long int> h{ 0 };
    std::vector<long long int> x{ 1 };
    for (int i = 1; i < str.size(); ++i)
    {
        h.push_back((h[i - 1] * x_ + str[i]) % p);
        x.push_back((x[i - 1] * x_) % p);
    }

    for (int i = 1; i < str.size() - 1; ++i)
    {
        if (equalSubstr(h, x, str.size() - i - 1, 1, i + 1, p))
        {
            std::cout << i;
            return 0;
        }
    }
    std::cout << str.size() - 1;
    return 0;
}