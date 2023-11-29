#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using iter = std::vector<long long>::iterator;

std::pair<iter, iter> partition(long long a, iter l, iter r)
{
    iter E = l, G = l, N = l;
    while (N != r)
    {
        if (*N < a)
        {
            std::swap(*G, *N);
            std::swap(*G, *E);
            ++E;
            ++G;
        }
        else if (*N == a)
        {
            std::swap(*G, *N);
            ++G;
        }
        ++N;
    }
    return std::pair<iter, iter>{E, G};
}


void inputSort(iter l, iter r)
{
    iter i = l;
    while (i != r)
    {
        iter j = i;
        while (j != r)
        {
            if (*i > *j)
                std::swap(*i, *j);
            ++j;
        }
        ++i;
    }
}
void piramSort(iter l, iter r)
{
    std::map<long long, long long> m;
    for (auto i = l; i < r; ++i)
    {
        ++m[*i];
    }
    for (auto i = m.begin(); i != m.end(); ++i)
    {
        for (size_t j = 0; j < i->second; ++j, ++l)
        {
            *l = i->first;
        }
    }
}

void quickSort(std::vector<long long>& arr, iter l, iter r, int depth)
{
    long long pivot;
    std::pair<iter, iter> tmp;
    if (depth > 31)
    {
        piramSort(l, r);
    }
    if (std::distance(l, r) > 16)
        while (l < r)
        {
            long long max = std::max(std::max(*l, *(r - 1)), *(l + std::distance(l, r) / 2));
            long long min = std::min(std::min(*l, *(r - 1)), *(l + std::distance(l, r) / 2));
            pivot = *(l + rand() % std::distance(l, r));
            tmp = partition(pivot, l, r);
            if (std::distance(l, tmp.first) >= std::distance(tmp.second, r))
            {
                quickSort(arr, tmp.second, r, ++depth);
                r = tmp.first;
            }
            else
            {
                quickSort(arr, l, tmp.first, ++depth);
                l = tmp.second;
            }
        }
    else
        inputSort(l, r);
}

int main()
{
    srand(time(NULL));
    unsigned long long n;
    std::ifstream f("input.txt");
    f >> n;
    std::vector<long long> v(n);
    for (size_t i = 0; i < n; ++i)
    {
        f >> v[i];
    }

    quickSort(v, v.begin(), v.end(), 0);

    std::ofstream out("output.txt");
    for (const auto& i : v)
        out << i << ' ';
    f.close();
    out.close();
    return 0;
}