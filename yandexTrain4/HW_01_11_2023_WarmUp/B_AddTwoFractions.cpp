#include <iostream>

struct Fraction
{
    Fraction() : a(0), b(1){}
    Fraction(const int& _a, const int _b)
    {
        int k = NOD(std::max(_a, _b), std::min(_a, _b));
        a = _a / k;
        b = _b / k;
    }

    Fraction operator+(Fraction& r)
    {
        Fraction res(a * r.b + r.a * b, b * r.b);
        return res;
    }

    int NOD(int _a, int _b)
    {
        if (_a % _b == 0) return _b;
        return NOD(_b, _a % _b);
    }

    int a;
    int b;
};


int main()
{
    Fraction d1, d2;
    std::cin >> d1.a >> d1.b >> d2.a >> d2.b;

    Fraction res = d1 + d2;
    std::cout << res.a << ' ' << res.b;

    return 0;
}