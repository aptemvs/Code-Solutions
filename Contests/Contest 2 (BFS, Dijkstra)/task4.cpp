#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int main()
{
    int K = 0, N = 0;
    int j = 0, i = 0;
    int m = 0, s = 0;

    std::cin >> K >> N;
    std::cin >> j >> i;
    std::cin >> m >> s;

    j--;
    i--;
    m--;
    s--;

    std::vector<std::vector<bool>> visited(K, std::vector<bool>(N, false));
    std::queue<std::pair<int, int>> q;

    const int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    const int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    q.push({j, i});
    visited[j][i] = true;

    while (!q.empty())
    {
        int x = q.front().second;
        int y = q.front().first;
        q.pop();

        if (x == s && y == m)
        {
            std::cout << "YES" << '\n';
            return 0;
        }

        for (int k = 0; k < 8; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx >= 0 && nx < N && ny >= 0 && ny < K && !visited[ny][nx])
            {
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }

    std::cout << "NO" << '\n';
    return 0;
}
