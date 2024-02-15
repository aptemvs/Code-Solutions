#include <iostream>
#include <vector>

class Solution
{
public:
    static std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> row(rowIndex + 1, 0);
        row.front() = row.back() = 1;

        for (int i = 0; i < (rowIndex >> 1); i++)
        {
            int number = static_cast<size_t>(row[i]) *
                         static_cast<size_t>((rowIndex - i)) /
                         (i + 1);
            row[i + 1] = row[rowIndex - i - 1] = number;
        }

        return row;
    }
};
