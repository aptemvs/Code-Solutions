#include <iostream>

class Solution
{
public:
    int lengthOfLastWord(const std::string& str)
    {
        int length = 0;
        bool word_found = false;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[str.size() - i - 1] != ' ')
            {
                length++;
                word_found = true;
            }
            if (str[str.size() - i - 1] == ' ' and word_found)
            {
                return length;
            }
        }
        return length;
    }
};
