#include <iostream>

int main(int argc, char* argv[])
{
    int room, cond;
    std::cin >> room >> cond;
    std::string str;
    std::cin >> str;
    if (str == "freeze")
    {
        if (cond < room)
            std::cout << cond;
        else
            std::cout << room;
    }
    else if (str == "heat")
    {
        if (cond < room)
            std::cout << room;
        else
            std::cout << cond;
    }
    else if (str == "auto")
    {
        std::cout << cond;
    }
    else if (str == "fan")
    {
        std::cout << room;
    }
    return 0;
}