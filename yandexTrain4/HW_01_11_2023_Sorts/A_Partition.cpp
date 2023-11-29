#include <iostream>
#include <vector>
#include <functional>

template <class Iterator>
Iterator partition(int a, Iterator l, Iterator r)
{
    Iterator E = l, G = l, N = l;
    while (N != r)
    {
        if (*N < a)
        {
            std::swap(*G, *N);
            std::swap(*G, *E);
            ++N;
            ++E;
            ++G;
        }
        else if (*N == a)
        {
            std::swap(*G, *N);
            ++G;
            ++N;
        }
        else
        {
            ++N;
        }
    }
    return E;
}


int main()
{
    size_t n;
    std::cin >> n;

    std::vector<int> a(n);
    for (size_t i = 0; i < n; ++i)
        std::cin >> a[i];

    int pivot;
    std::cin >> pivot;

    std::function pred = [pivot](int b) { return b < pivot; };
    std::vector<int>::iterator ind = partition(pivot, a.begin(), a.end());
    std::cout << std::distance(a.begin(), ind) << " " << a.size() - std::distance(a.begin(), ind);

    return 0;
}