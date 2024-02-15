#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int N = 0, M = 0, v = 0;
    std::cin >> N >> M >> v;

    std::vector<std::vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        int u, w;
        std::cin >> u >> w;
        graph[u].push_back(w);
        graph[w].push_back(u);
    }

    std::vector<bool> visited(N + 1, false);
    std::queue<int> q;
    std::vector<int> result;

    q.push(v);
    visited[v] = true;

    while (!q.empty())
    {
        int current = q.front();
        q.pop();
        result.push_back(current);

        for (int neighbor: graph[current])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    std::cout << result.size() << '\n';

    for (int node: result)
    {
        std::cout << node << " ";
    }

    return 0;
}
