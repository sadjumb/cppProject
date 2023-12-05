#include <iostream>
#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int>& nums)
    {
        auto it1 = nums.begin();
        auto it2 = nums.begin();
        for (;it2 != nums.end(); ++it2)
        {
            if (*it2 != 0)
            {
                std::swap(*it1, *it2);
                ++it1;
            }
        }
        return;
    }
};

int main()
{
    std::vector<int> v{ 0,0,0,0 };
    Solution a;
    a.moveZeroes(v);
    for (const auto& i : v)
        std::cout << i << ' ';
    return 0;
}