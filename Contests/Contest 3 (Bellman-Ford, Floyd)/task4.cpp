#include <iostream>
#include <vector>
#include <climits>
#include <queue>

const long long INF = LLONG_MAX;

struct Edge
{
    long long src, dest, weight;
};

std::pair<std::vector<long long>, std::vector<bool>>
bellman_ford(long long n, long long s, const std::vector<Edge>& edges)
{
    std::vector<long long> dist(n, INF);
    dist[s] = 0;

    for (long long i = 0; i < n - 1; i++)
    {
        for (const auto& edge: edges)
        {
            if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest])
            {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    std::vector<bool> in_negative_cycle(n, false);

    for (const auto& edge: edges)
    {
        if (dist[edge.src] != INF && dist[edge.src] + edge.weight < dist[edge.dest])
        {
            in_negative_cycle[edge.dest] = true;
        }
    }

    std::queue<long long> q;
    for (long long i = 0; i < n; i++)
    {
        if (in_negative_cycle[i])
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        long long u = q.front();
        q.pop();

        for (const auto& edge: edges)
        {
            if (edge.src == u)
            {
                long long v = edge.dest;
                if (!in_negative_cycle[v])
                {
                    in_negative_cycle[v] = true;
                    q.push(v);
                }
            }
        }
    }

    return {dist, in_negative_cycle};
}

int main()
{
    long long n, m, s;
    std::cin >> n >> m >> s;
    s--;

    std::vector<Edge> edges(m);
    for (long long i = 0; i < m; i++)
    {
        std::cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
        edges[i].src--;
        edges[i].dest--;
    }

    auto result = bellman_ford(n, s, edges);
    auto dist = result.first;
    auto in_negative_cycle = result.second;

    for (long long i = 0; i < n; i++)
    {
        if (dist[i] == INF)
        {
            std::cout << "*" << '\n';
        }
        else if (in_negative_cycle[i])
        {
            std::cout << "-" << '\n';
        }
        else
        {
            std::cout << dist[i] << "\n";
        }
    }

    return 0;
}
