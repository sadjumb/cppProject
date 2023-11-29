#include <iostream>
#include <map>
#include <fstream>
//+

int main()
{
    std::map<char, size_t> m;
    char c;
    std::fstream file("input.txt", std::ios_base::in);
    while(file >> c)
        ++m[c];
    
    int max = 0;
    for (const auto& i : m)
        if (i.second > max)
            max = i.second;

    for (max; max > 0; --max)
    {
        for (auto& i : m)
            if (i.second == max)
                {
                    std::cout << '#';
                    --i.second;
                }
            else
                std::cout << ' ';
        std::cout << std::endl;
    }
    for (const auto& i : m)
        std::cout << i.first;

    return 0;
}