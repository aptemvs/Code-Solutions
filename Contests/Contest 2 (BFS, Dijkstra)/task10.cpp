#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> bfs(const std::vector<std::vector<int>>& adj, const std::vector<int>& barons)
{
    int N = adj.size();
    std::vector<int> dist(N, -1);
    std::vector<int> prev(N, -1);
    std::queue<int> q;
    dist[0] = 0;
    q.push(0);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next: adj[cur])
        {
            int cost = (barons[cur] != barons[next]);
            if (dist[next] == -1 || dist[cur] + cost < dist[next])
            {
                dist[next] = dist[cur] + cost;
                prev[next] = cur;
                q.push(next);
            }
        }
    }

    return prev;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<int> barons(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> barons[i];
    }

    std::vector<std::vector<int>> adj(N);
    for (int i = 0; i < M; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    std::vector<int> prev = bfs(adj, barons);

    if (prev[N - 1] == -1)
    {
        std::cout << "impossible" << "\n";
    }
    else
    {
        std::vector<int> path;
        for (int v = N - 1; v != -1; v = prev[v])
        {
            path.push_back(v);
        }
        std::reverse(path.begin(), path.end());

        int cost = 0;
        for (int i = 0; i < path.size() - 1; ++i)
        {
            if (barons[path[i]] != barons[path[i + 1]])
            {
                cost++;
            }
        }

        std::cout << cost << " " << path.size() << "\n";
        for (int v: path)
        {
            std::cout << v + 1 << " ";
        }
        std::cout << '\n';
    }

    return 0;
}
