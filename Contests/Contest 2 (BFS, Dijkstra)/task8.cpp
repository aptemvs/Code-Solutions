#include <iostream>
#include <vector>
#include <queue>

const int INF = INT32_MAX;
using pii = std::pair<int, int>;

int dijkstra(const std::vector<std::vector<int>>& graph, int start, int end)
{
    int n = graph.size();
    std::vector<int> distances(n, INF);
    std::vector<bool> visited(n, false);
    distances[start] = 0;

    std::priority_queue<pii, std::vector<pii>, std::greater<pii>> pq;
    pq.push({0, start});

    while (!pq.empty())
    {
        int current = pq.top().second;
        pq.pop();

        if (visited[current])
        {
            continue;
        }
        visited[current] = true;

        for (int neighbor = 0; neighbor < n; ++neighbor)
        {
            if (graph[current][neighbor] != -1)
            {
                int new_distance = distances[current] + graph[current][neighbor];
                if (new_distance < distances[neighbor])
                {
                    distances[neighbor] = new_distance;
                    pq.push({new_distance, neighbor});
                }
            }
        }
    }

    return distances[end] == INF ? -1 : distances[end];
}

int main()
{
    int N, S, F;
    std::cin >> N >> S >> F;
    --S;
    --F;

    std::vector<std::vector<int>> graph(N, std::vector<int>(N));
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            std::cin >> graph[i][j];
        }
    }

    std::cout << dijkstra(graph, S, F) << '\n';
    return 0;
}
