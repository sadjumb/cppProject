#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int heightChecker(std::vector<int>& heights)
    {
        std::vector<int> cp(heights);
        std::sort(cp.begin(), cp.end());
        int k = 0;
        for (size_t i = 0; i < heights.size(); ++i)
        {
            if (heights[i] != cp[i])
                ++k;
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
    Solution a;
    std::cout << a.heightChecker(v) << std::endl;
    for (const auto& i : v)
        std::cout << i << ' ';
    return 0;
}