#include <iostream>

void sort2(int& a, int& b)
{
    if (a > b)
        std::swap(a, b);
}

int main()
{
    int a, b, c, d, e;
    std::cin >> a >> b >> c >> d >> e;
    sort2(d, e);

    sort2(a, b);
    sort2(b, c);
    sort2(a, b);


    if (a <= d && b <= e)
        std::cout << "YES";
    else
        std::cout << "NO";
    return 0;
}