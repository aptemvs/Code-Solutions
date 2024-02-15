#include <iostream>
#include <vector>
#include <unordered_map>

class Solution
{
public:
    static std::vector<int> twoSum(const std::vector<int>& nums, int target)
    {
        std::unordered_map<int, int> map; // <value, index>

        for (int index = 0; index < nums.size(); index++)
        {
            if (map.count(target - nums[index]))
            {
                return {index, map[target - nums[index]]};
            }

            map[nums[index]] = index;
        }

        return {-1, -1};
    }
};
