#include <iostream>

void getCx(int n)
{
    std::cin >> n;
    long long x = 1;
    for (size_t i = 1, j = 1, count = 1; count <= n; ++count)
        if (i * i > j * j * j)
        {
            x = j * j * j;
            ++j;
        }
        else if (i * i == j * j * j)
        {
            ++i;
            --count;
        }
        else
        {
            x = i * i;
            ++i;
        }
    std::cout << x;
    //return x;
}

#include <vector>

std::vector<int> zFunction(std::string s)
{
    size_t n = s.length();
    std::vector<int> z(n);
    z[0] = 1;
    std::cout << "1 ";
    for (int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
            z[i] = std::min(r - i + 1, z[i - l]);
        while (i - z[i] >= 0 && s[z[i]] == s[i - z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
        std::cout << z[i] << ' ';
    }
    return z;
}


int main()
{
    int n;
    std::cin >> n;

    std::string str;
    std::cin >> str;
    zFunction(str);

    return 0;
}