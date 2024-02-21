#include <vector>


class Solution
{
public:
    int maxArea(const std::vector<int>& height)
    {
        int max_volume = 0;
        int current_volume = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left != right)
        {
            current_volume = std::min(height[left], height[right]) * (right - left);
            max_volume = std::max(max_volume, current_volume);

            height[left] < height[right] ? left++ : right--;
        }

        return max_volume;
    }
};
