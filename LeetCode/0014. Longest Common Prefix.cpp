#include <vector>
#include <string>


class Solution
{
public:

    std::string longestCommonPrefix(const std::vector<std::string>& strs)
    {
        std::string common_prefix = strs[0];

        for (int i = 0; i < common_prefix.size(); i++)
        {
            for (const std::string& str: strs)
            {
                if (i > str.size() || str[i] != common_prefix[i])
                {
                    return common_prefix.substr(0, i);
                }
            }
        }

        return common_prefix;
    }
};