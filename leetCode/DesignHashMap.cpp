#include <vector>
#include <iostream>

class MyHashMap
{
public:
    MyHashMap() : v(1000001, -1)
    {

    }

    void put(int key, int value)
    {
        v[key] = value;
    }

    int get(int key)
    {
        return v[key];
    }

    void remove(int key)
    {
        v[key] = -1;
    }
    std::vector<int> v;
};