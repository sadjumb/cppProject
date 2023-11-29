#include <iostream>
#include <vector>

int main(int argc, char* argv[])
{
    long long k;
    std::cin >> k;
    const long long capacity = k;

    long long n;
    std::cin >> n;
    std::vector<unsigned long long> v(n + 1);
    unsigned long long sum = 0;

    for (long long i = 0; i < n; ++i)
    {
        std::cin >> v[i + 1];
        sum += v[i + 1];
    }
    while (v.size() > 1 && v[v.size() - 1] == 0)
        v.pop_back();

    if (sum != 0 && sum < capacity)
    {
        std::cout << (v.size() - 1) * 2;
        return 0;
    }

    unsigned long long t = 0;
    k = 0;
    for (long long i = v.size() - 1; i > 0;)
    {
        if (v[i] < 1)
        {
            v.pop_back();
            --i;
            continue;
        }
        if (v[i] >= capacity)
        {
            t += i * 2 * (v[i] / capacity);
            v[i] %= capacity;
        }
        else
        {
            t += i;
            k = v[i];
            v[i] = 0;
            while (k != capacity && i > 0)
            {
                if (v[i] < 1)
                {
                    v.pop_back();
                    --i;
                    ++t;
                    continue;
                }
                if (v[i] < (capacity - k))
                {
                    k += v[i];
                    v[i] = 0;
                }
                else
                {
                    v[i] -= (capacity - k);

                    t += i;
                    k = capacity;
                }
            }
        }
    }
    std::cout << t;
    return 0;
}