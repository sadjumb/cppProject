#include <vector>
#include <unordered_map>

class Solution
{
public:
    int singleNumber(std::vector<int>& nums)
    {
        std::unordered_map<int, int> um;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            ++um[nums[i]];
        }
        for (const auto& i : um)
        {
            if (i.second == 1)
                return i.first;
        }
        return -1;
    }
};