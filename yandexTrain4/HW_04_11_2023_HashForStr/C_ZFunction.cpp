#include <iostream>
#include <vector>


int binaryFind(const std::vector<long long>& h, const std::vector<long long>& x, long long p, size_t r)
{
    size_t l = 1;

    return r;
}

long long getHash(std::vector<long long> h, int l, int r)
{
    long long res = h[r];
    if (l > 0) res -= h[l - 1];
    return res;
}

bool equalSubstr(const std::vector<long long int>& h, const std::vector<long long int>& x, int l, int s1, int s2, long long int p)
{
    return (h[s1 + l - 1] + h[s2 - 1] * x[l]) % p == (h[s2 + l - 1] + h[s1 - 1] * x[l]) % p;
}

int main()
{
    std::vector<long long> h{ 0 };
    std::vector<long long> x{ 1 };

    long long p = 1e9 + 7;
    int x_ = 257;

    std::string str;
    std::cin >> str;
    str = ' ' + str;
    std::vector<long long> z(str.size());
    //h[0] = str[0];
    for (size_t i = 1; i < str.size(); ++i)
    {
        h.push_back((h[i - 1] * x_ + str[i]) % p);
        x.push_back((x[i - 1] * x_) % p);
    }
    std::cout << 0 << ' ';
    for (size_t i = 1; i < str.size(); ++i)
    {
        int l = 1, r = str.size() - i;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (equalSubstr(h, x, str.size() - mid - 1, mid, i, p))
            {
                z[i] = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
    }
    for (size_t i = 0; i < z.size(); ++i)
        std::cout << z[i] << ' ';

    return 0;
}