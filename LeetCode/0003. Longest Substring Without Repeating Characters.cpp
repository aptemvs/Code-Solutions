#include <set>
#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        int i = 0;
        int j = 0;
        int max_length = 0;

        std::set<char> letters;

        while (j < s.size())
        {
            if (letters.find(s[j]) == letters.end())
            {
                letters.insert(s[j++]);
            }
            else
            {
                letters.erase(s[i++]);
            }

            max_length = std::max(max_length, j - i);
        }

        return max_length;
    }
};