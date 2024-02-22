#include <string>
#include <map>


class Solution
{
public:
    std::string intToRoman(int number)
    {
        std::string roman;

        std::map<int, std::string, std::greater<int>> romanMap = {
                {1,    "I"},
                {4,    "IV"},
                {5,    "V"},
                {9,    "IX"},
                {10,   "X"},
                {40,   "XL"},
                {50,   "L"},
                {90,   "XC"},
                {100,  "C"},
                {400,  "CD"},
                {500,  "D"},
                {900,  "CM"},
                {1000, "M"}
        };

        for (const auto& [num, rom]: romanMap)
        {
            while (num <= number)
            {
                number -= num;
                roman += rom;
            }
        }

        return roman;
    }
};