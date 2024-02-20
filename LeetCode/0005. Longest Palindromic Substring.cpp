#include <string>
#include <vector>


class Solution
{
public:
    static std::vector<std::vector<bool>> getDiagonalMatrix(int size)
    {
        std::vector<std::vector<bool>> table(size, std::vector<bool>(size, false));

        for (int i = 0; i < size; i++)
        {
            table[i][i] = true;
        }

        return table;
    }

    static std::string longestPalindrome(const std::string& str)
    {
        std::pair<int, int> answer = {0, 1}; // {start, length}
        std::vector<std::vector<bool>> table = Solution::getDiagonalMatrix(str.size());

        for (int start = 0; start < str.size() - 1; start++)
        {
            if (str[start] == str[start + 1])
            {
                table[start][start + 1] = true;
                answer = {start, 2};
            }
        }

        for (int len = 3; len <= str.size(); len++)
        {
            for (int start = 0; start + len <= str.size(); start++)
            {
                int end = start + len - 1;

                if (str[start] == str[end] && table[start + 1][end - 1])
                {
                    table[start][end] = true;
                    answer = {start, len};
                }
            }
        }

        return str.substr(answer.first, answer.second);
    }
};