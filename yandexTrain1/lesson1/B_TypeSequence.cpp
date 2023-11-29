#include <iostream>
#include <cmath>

int main()
{
    bool CONSTANT = false;
    bool ASCENDING = true;
    bool WEAKLY_ASCENDING = false;
    bool DESCENDING = true;
    bool WEAKLY_DESCENDING = false;
    bool RANDOM = true;
    long long int a, b;
    std::cin >> a >> b;
    if (b != -2 * pow(10, 9))
    {
        if (a > b && (DESCENDING || WEAKLY_DESCENDING))
        {
            if (!CONSTANT)
            {
                WEAKLY_DESCENDING = false;
            }
            ASCENDING = false;
            WEAKLY_ASCENDING = false;
        }
        else if (a < b && (ASCENDING || WEAKLY_ASCENDING))
        {
            if (!CONSTANT)
            {
                WEAKLY_ASCENDING = false;
            }
            DESCENDING = false;
            WEAKLY_DESCENDING = false;
        }
        else if (a == b)
        {
            CONSTANT = true;
            if (ASCENDING && DESCENDING)
            {
                WEAKLY_ASCENDING = true;
                WEAKLY_DESCENDING = true;
            }
            else if (ASCENDING)
            {
                WEAKLY_ASCENDING = true;
                WEAKLY_DESCENDING = false;
            }
            else if (DESCENDING)
            {
                WEAKLY_ASCENDING = false;
                WEAKLY_DESCENDING = true;
            }
            ASCENDING = false;
            DESCENDING = false;
        }
        std::swap(a, b);
    }
    else
    {
        std::cout << "CONSTANT";
        return 0;
    }

    while (std::cin >> b && b != -2 * pow(10, 9))
    {
        if (a < b && (DESCENDING || WEAKLY_DESCENDING))
        {
            if ((ASCENDING || WEAKLY_ASCENDING) && !CONSTANT)
            {
                RANDOM = true;
                std::cout << "RANDOM";
                return 0;
            }
            CONSTANT = false;
            ASCENDING = false;
            WEAKLY_ASCENDING = false;
        }
        else if (a > b && (ASCENDING || WEAKLY_ASCENDING))
        {
            if ((DESCENDING || WEAKLY_DESCENDING) && !CONSTANT)
            {
                RANDOM = true;
                std::cout << "RANDOM";
                return 0;
            }
            if (!WEAKLY_ASCENDING)
                CONSTANT = false;
            DESCENDING = false;
            WEAKLY_DESCENDING = false;
        }
        else if (a == b && CONSTANT)
        {
            if (!WEAKLY_ASCENDING && !WEAKLY_ASCENDING)
                CONSTANT = true;
            if (ASCENDING && DESCENDING)
            {
                WEAKLY_ASCENDING = true;
                WEAKLY_DESCENDING = true;
            }
            else if (ASCENDING)
            {
                WEAKLY_ASCENDING = true;
                WEAKLY_DESCENDING = false;
            }
            else if (DESCENDING)
            {
                WEAKLY_ASCENDING = false;
                WEAKLY_DESCENDING = true;
            }
            ASCENDING = false;
            DESCENDING = false;
        }
        std::swap(a, b);
    }
    if (ASCENDING)
        std::cout << "ASCENDING";
    else if (DESCENDING)
        std::cout << "DESCENDING";
    else if (CONSTANT)
        std::cout << "CONSTANT";
    else if (WEAKLY_ASCENDING)
        std::cout << "WEAKLY ASCENDING";
    else if (WEAKLY_DESCENDING)
        std::cout << "WEAKLY DESCENDING";

    return 0;
}