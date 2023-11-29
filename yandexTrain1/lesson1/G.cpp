#include <iostream>
#include <fstream>

int main()
{
    int n;
    std::ifstream in("input.txt");
    in >> n;
    int max = n;
    int preMax = INT32_MIN;
    int min = n;
    int preMin = INT32_MAX;
    while (in >> n)
    {
        if (max < n)
        {
            preMax = max;
            max = n;
        }
        else if (preMax < n)
        {
            preMax = n;
        }
        if (min > n)
        {
            preMin = min;
            min = n;
        }
        else if (preMin > n)
        {
            preMin = n;
        }

    }
    if (preMin == 0 || min == 0)
    {
        min = 1;
        preMin = 1;
    }
    if ((max / min) * (preMax / min) >= 1)
    {
        std::cout << std::min(max, preMax) << ' ' << std::max(max, preMax);
    }
    else
    {
        std::cout << std::min(min, preMin) << ' ' << std::max(min, preMin);
    }
    in.close();
    return 0;
}