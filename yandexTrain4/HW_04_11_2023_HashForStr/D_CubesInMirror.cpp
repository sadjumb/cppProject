#include <iostream>
#include <vector>


int main()
{
    long long p = 1e10 + 7;
    long long x_ = 10;
    std::vector<long long> x{ 1 }, x_reverse{ 1 };
    std::vector<long long> h{ 0 }, h_reverse{ 0 };
    size_t N, M;
    std::cin >> N >> M;
    std::vector<long long> in(N);
    for (size_t i = 0; i < N; ++i)
    {
        std::cin >> in[i];
        x.push_back(x_ * x[i] % p);
        h.push_back((h[i] * x_ + in[i]) % p);
    }
    for (int i = N - 1; i > -1; --i)
    {
        x_reverse.push_back(x_ * x_reverse[i] % p);
        x_reverse.push_back((h_reverse[i] * x_ + in[i]) % p);
    }

    for (size_t i = )

        return 0;
}