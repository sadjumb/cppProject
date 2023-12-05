#include <iostream>

class Solution
{
public:
    bool isHappy(int n)
    {
        int sum;
        while (n > 3)
        {
            int sum = 0;
            while (n / 10 || n > 3)
            {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }

        if (n == 1)
            return true;
        return false;
    }
};

int main()
{

    return 0;
}