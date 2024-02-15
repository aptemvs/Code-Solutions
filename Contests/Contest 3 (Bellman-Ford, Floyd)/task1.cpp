#include <iostream>
#include <vector>
#include <algorithm>

const int INF = 1e9;

void read_graph(std::vector<std::vector<int>>& graph)
{
    int n = graph.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cin >> graph[i][j];
            if (graph[i][j] == 0 && i != j)
            {
                graph[i][j] = INF;
            }
        }
    }
}

void floyd_warshall(std::vector<std::vector<int>>& graph)
{
    int n = graph.size();
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (graph[i][k] < INF && graph[k][j] < INF)
                {
                    graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }
}

void print_matrix(const std::vector<std::vector<int>>& matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            std::cout << matrix[i][j] << (j == n - 1 ? "\n" : " ");
        }
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));

    read_graph(graph);
    floyd_warshall(graph);
    print_matrix(graph);

    return 0;
}
