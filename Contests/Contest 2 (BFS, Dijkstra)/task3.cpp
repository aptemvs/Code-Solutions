#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int main()
{
    int N = 0, M = 0;
    std::cin >> N >> M;

    std::vector<std::vector<int>> maze(N, std::vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            std::cin >> maze[i][j];
        }
    }

    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    std::cin >> x1 >> y1 >> x2 >> y2;

    x1--;
    y1--;
    x2--;
    y2--;

    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
    std::vector<std::vector<int>> distance(N, std::vector<int>(M, -1));
    std::queue<std::pair<int, int>> q;

    q.push({x1, y1});
    visited[y1][x1] = true;
    distance[y1][x1] = 0;

    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx] && maze[ny][nx] == 0)
            {
                q.push({nx, ny});
                visited[ny][nx] = true;
                distance[ny][nx] = distance[y][x] + 1;
            }
        }
    }

    std::cout << distance[y2][x2] << '\n';

    return 0;
}
