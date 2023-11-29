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
    //return res;

}

int main()
{
    int n;
    std::cin >> n;
    std::vector<int> f(n);
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> f[i];
    }
    std::cin >> n;
    std::vector<int> s(n);
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> s[i];
    }
    std::vector<int> res(s.size() + f.size());
    merger(f.begin(), f.end(), s.begin(), s.end(), res.begin());
    for (const auto& i : res)
        std::cout << i << ' ';

    return 0;
}