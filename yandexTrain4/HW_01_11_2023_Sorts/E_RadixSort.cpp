#include <iostream>
#include <vector>
#include <fstream>


void radixSort(std::vector<std::string>& vStr)
{

    std::cout << "Initial array:\n";
    for (size_t i = 0; i < vStr.size() - 1; ++i)
        std::cout << vStr[i] << ", ";
    if (vStr.size())
        std::cout << vStr[vStr.size() - 1];
    std::cout << std::endl;

    std::vector<std::vector<std::string>> tmp(10);

    for (size_t i = 0; i < vStr[0].size(); ++i)
    {
        for (size_t j = 0; j < vStr.size(); ++j)
        {
            tmp[vStr[j][vStr[j].size() - 1 - i] - 48].push_back(vStr[j]);
        }

        std::cout << "**********\n";
        std::cout << "Phase " << i + 1 << std::endl;
        for (size_t k = 0, t = 0; k < tmp.size(); ++k)
        {
            std::cout << "Bucket " << k << ": ";
            if (!tmp[k].size())
            {
                std::cout << "empty\n";
                continue;
            }

            for (size_t j = 0; j < tmp[k].size() - 1; ++j)
            {
                std::cout << tmp[k][j] << ", ";
                vStr[t++] = std::move(tmp[k][j]);
            }
            std::cout << tmp[k][tmp[k].size() - 1];
            vStr[t++] = std::move(tmp[k][tmp[k].size() - 1]);

            tmp[k].clear();
            std::cout << std::endl;
        }
    }
    std::cout << "**********\n";
    std::cout << "Sorted array:\n";
    for (size_t i = 0; i < vStr.size() - 1; ++i)
        std::cout << vStr[i] << ", ";
    if (vStr.size())
        std::cout << vStr[vStr.size() - 1];

}


int main()
{
    size_t n = 0;
    std::cin >> n;
    std::vector<std::string> vStr(n);
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> vStr[i];
    }
    radixSort(vStr);
    return 0;
}