#include <iostream>
#include <vector>


void merger(std::vector<int>::iterator itFB, std::vector<int>::iterator itFE, std::vector<int>::iterator itSB, std::vector<int>::iterator itSE, std::vector<int>::iterator res)
{
    for (;itFB != itFE && itSB != itSE; ++res)
    {
        if (*itFB <= *itSB)
        {
            *res = *itFB;
            ++itFB;
        }
        else
        {
            *res = *itSB;
            ++itSB;
        }
    }
    for (;itSB != itSE; ++itSB, ++res)
    {
        *res = *itSB;
    }
    for (;itFB != itFE; ++itFB, ++res)
    {
        *res = *itFB;
    }
}

std::vector<int> mergeSort(std::vector<int>& v, std::vector<int>::iterator l, std::vector<int>::iterator r)
{
    if (v.size() < 1)
        return {};
    std::vector<int>::iterator pivot = l + std::ranges::distance(l, r) / 2;
    std::vector<int> res(std::ranges::distance(l, r));
    if (l + 1 == r)
    {
        std::copy(l, r, res.begin());
        return res;
    }
    std::vector<int> v1 = mergeSort(v, l, pivot);
    std::vector<int> v2 = mergeSort(v, pivot, r);

    merger(v1.begin(), v1.end(), v2.begin(), v2.end(), res.begin());
    return res;
}

int main()
{
    size_t n = 0;
    std::cin >> n;
    std::vector<int> v(n);
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }

    v = mergeSort(v, v.begin(), v.end());
    for (const auto& i : v)
    {
        std::cout << i << ' ';
    }
    return 0;
}