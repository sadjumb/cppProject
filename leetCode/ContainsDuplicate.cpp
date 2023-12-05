#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool containsDuplicate(std::vector<int>& nums)
    {
        std::unordered_set<int> us;
        for (size_t i = 0; i < nums.size(); ++i)
            if (us.contains(nums[i]))
                return true;
            else
                us.insert(nums[i]);
        return false;
    }
};