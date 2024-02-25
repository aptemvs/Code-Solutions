#include <vector>


class Solution
{
public:

    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        std::vector<std::vector<bool>> rows(BOARD_SIZE, std::vector<bool>(BOARD_SIZE, false));
        std::vector<std::vector<bool>> cols(BOARD_SIZE, std::vector<bool>(BOARD_SIZE, false));
        std::vector<std::vector<bool>> grids(BOARD_SIZE, std::vector<bool>(BOARD_SIZE, false));

        for (int r = 0; r < BOARD_SIZE; r++)
        {
            for (int c = 0; c < BOARD_SIZE; c++)
            {
                if (board[r][c] == '.')
                {
                    continue;
                }

                int num = board[r][c] - '1';
                int grid_num = (r / 3) * 3 + (c / 3);

                if (rows[r][num] || cols[c][num] || grids[grid_num][num])
                {
                    return false;
                }

                rows[r][num] = true;
                cols[c][num] = true;
                grids[grid_num][num] = true;
            }
        }
        return true;
    }

public:
    const int BOARD_SIZE = 9;
};