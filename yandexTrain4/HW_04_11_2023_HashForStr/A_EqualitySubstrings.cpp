#include <iostream>
#include <vector>
#include <string>
#include <cmath>

/*
    "abacabab" ~ 1 * x^(size - 1) + 2 * x^(size - 2) + ... + 2 * x^(size - size) = P_(size-1)
*/

int main()
{
    int x_ = 257;
    int p = pow(10, 9) + 7;
    size_t q;
    size_t l, s1, s2;
    std::string strIn;
    std::cin >> strIn;
    strIn = " " + strIn;

    std::vector<long int> h{ 0 };
    std::vector<long int> x{ 1 };

    for (size_t i = 1; i < strIn.size(); ++i)
    {
        h.push_back((x_ * h[i - 1] + strIn[i]) % p);
        x.push_back(x_ * x[i - 1]);
    }

    std::cin >> q;
    for (size_t i = 0; i < q; ++i)
    {
        std::cin >> l >> s1 >> s2;
        if (s1 == s2)
            std::cout << "yes\n";
        else if ((h[s1 + l] + h[s2] * x[l]) % p == (h[s2 + l] + h[s1] * x[l]) % p)
            std::cout << "yes" << std::endl;
        else
            std::cout << "no" << std::endl;
    }
    return 0;
}