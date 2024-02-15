#include <iostream>
#include <vector>
#include <algorithm>

const int INF = INT32_MAX;

std::vector<int> shortest_path(const std::vector<std::vector<int>>& graph, int start, int finish)
{
    int n = graph.size();
    std::vector<int> dist(n, INF), prev(n, -1);
    dist[start] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int u = 0; u < n; ++u)
        {
            for (int v = 0; v < n; ++v)
            {
                if (graph[u][v] != -1 && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                {
                    dist[v] = dist[u] + graph[u][v];
                    prev[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < n; ++u)
    {
        for (int v = 0; v < n; ++v)
        {
            if (graph[u][v] != -1 && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
            {
                return std::vector<int>{-1};
            }
        }
    }

    if (dist[finish] == INF)
    {
        return std::vector<int>{-1};
    }

    std::vector<int> path;
    for (int v = finish; v != -1; v = prev[v])
    {
        path.push_back(v);
    }
    std::reverse(path.begin(), path.end());
    return path;
}

int main()
{
    int N, S, F;
    std::cin >> N >> S >> F;
    S--;
    F--;

    std::vector<std::vector<int>> graph(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> graph[i][j];
        }
    }

    std::vector<int> path = shortest_path(graph, S, F);
    if (path.size() == 1 && path[0] == -1)
    {
        std::cout << -1 << '\n';
    }
    else
    {
        for (int v: path)
        {
            std::cout << v + 1 << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
