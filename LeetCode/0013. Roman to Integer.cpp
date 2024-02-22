#include <string>
#include <unordered_map>


class Solution
{
public:
    int romanToInt(const std::string& roman)
    {

        std::unordered_map<char, int> romanMap = {
                {'I', 1},
                {'V', 5},
                {'X', 10},
                {'L', 50},
                {'C', 100},
                {'D', 500},
                {'M', 1000}
        };

        int total = 0;
        int curr = 0;
        int prev = 0;

        for (int i = roman.size(); i >= 0; i--)
        {
            curr = romanMap[roman[i]];

            if (curr >= prev)
            {
                total += curr;
            }
            else
            {
                total -= curr;
            }

            prev = curr;
        }

        return total;
    }
};