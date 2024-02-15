#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int main()
{
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> table(n, std::vector<int>(m));
    std::queue<std::pair<int, int>> ones_positions;
    std::vector<std::vector<int>> result(n, std::vector<int>(m, -1));
    std::vector<std::pair<int, int>> directions = {{1,  0},
                                                   {-1, 0},
                                                   {0,  1},
                                                   {0,  -1}};

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cin >> table[i][j];
            if (table[i][j] == 1)
            {
                ones_positions.push({i, j});
                result[i][j] = 0;
            }
        }
    }

    while (!ones_positions.empty())
    {
        int x = ones_positions.front().first;
        int y = ones_positions.front().second;
        ones_positions.pop();

        for (const std::pair<int, int>& direction: directions)
        {
            int new_x = x + direction.first;
            int new_y = y + direction.second;

            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && result[new_x][new_y] == -1)
            {
                result[new_x][new_y] = result[x][y] + 1;
                ones_positions.push({new_x, new_y});
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            std::cout << result[i][j] << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
