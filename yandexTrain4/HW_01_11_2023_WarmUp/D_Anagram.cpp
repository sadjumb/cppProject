#include <iostream>
#include <map>

int main()
{
    std::map<char, size_t> m;
    std::string str;
    std::cin >> str;
    for (size_t i = 0; i < str.size(); ++i)
        ++m[str[i]];
    std::cin >> str;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (m[str[i]] == 0)
        {
            std::cout << "NO";
            return 0;
        }
        --m[str[i]];
    }
    std::cout << "YES";
}