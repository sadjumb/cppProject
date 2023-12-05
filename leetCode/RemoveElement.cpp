#include <iostream>
#include <vector>

class Solution
{
public:
    int removeElement(std::vector<int>& nums, int val)
    {
        auto it1 = nums.begin();
        auto it2 = nums.begin();
        int k = 0;
        for (;it2 != nums.end(); ++it2)
        {
            if (*it2 != val)
            {
                std::swap(*it1, *it2);
                ++it1;
                ++k;
            }
        }
        return k;
    }
};

int main()
{
    size_t n = 0;
    std::cin >> n;
    std::vector<int> v(n);
    for (size_t i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }
    int val;
    std::cin >> val;
    Solution a;
    std::cout << a.removeElement(v, val) << std::endl;
    for (const auto& i : v)
        std::cout << i << ' ';
    return 0;
}