#include <iostream>
#include <vector>

class Solution
{
public:
    static std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> matrix;

        for (int i = 0; i < numRows; i++)
        {
            std::vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++)
            {
                row[j] = matrix[i - 1][j - 1] + matrix[i - 1][j];
            }

            matrix.push_back(row);
        }
        return matrix;
    }
};