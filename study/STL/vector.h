#pragma once
#include <stdexcept>

template<class T>
class vector
{
public:
    vector(size_t _n) : capacity(_n * 1.5 + 1), n(_n), arr(std::move(new T[capacity]{ 0 })) {}
    vector(size_t _n, const T& _val) : capacity(_n * 1.5 + 1), n(_n), arr(std::move(new T[capacity]{ _val })) {}
    vector() : capacity(0), n(0), arr(nullptr) {}
    vector(const vector& cp) : capacity(cp.capacity), n(cp.n), arr(new T[capacity]{ 0 })
    {
        for (size_t i = 0; i < n; ++i)
        {
            arr[i] = cp.arr[i];
        }
    }

    size_t size() const
    {
        return n;
    }

    void push_back(const T& elem)
    {
        if (capacity == n)
        {
            T* tmp = arr;
            capacity = n * 2 + 1;
            arr = new T[capacity];
            for (size_t i = 0; i < n; ++i)
            {
                arr[i] = tmp[i];
            }
            delete[] tmp;
        }
        arr[n] = elem;
        ++n;
    }

    void pop_back()
    {
        if (n != 0)
            --n;
    }

    class Iterator
    {
    public:
        Iterator()
    private:
        T* it;
    }

    ~vector()
    {
        delete arr;
        arr = nullptr;
    }

    const T& operator[](size_t index) const
    {
        if (n <= index)
        {
            throw std::out_of_range("Out of range");
        }
        return arr[i];
    }

    T& operator[](size_t index)
    {
        if (n <= index)
        {
            throw std::out_of_range("Out of range");
        }
        return arr[i];
    }

private:
    size_t capacity;
    size_t n;
    T* arr;
};