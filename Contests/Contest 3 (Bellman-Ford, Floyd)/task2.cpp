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
            int val;
            std::cin >> val;
            graph[i][j] = (val == -1 && i != j) ? INF : val;
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
                graph[i][j] = std::min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }
}

void find_diameter_and_radius(const std::vector<std::vector<int>>& graph, int& diameter, int& radius)
{
    int n = graph.size();
    diameter = 0;
    radius = INF;

    for (int i = 0; i < n; ++i)
    {
        int max_distance = 0;
        for (int j = 0; j < n; ++j)
        {
            if (i != j && graph[i][j] != INF)
            {
                max_distance = std::max(max_distance, graph[i][j]);
            }
        }
        diameter = std::max(diameter, max_distance);
        radius = std::min(radius, max_distance);
    }
}

int main()
{
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> graph(n, std::vector<int>(n));

    read_graph(graph);
    floyd_warshall(graph);

    int diameter, radius;
    find_diameter_and_radius(graph, diameter, radius);

    std::cout << diameter << "\n" << radius << std::endl;

    return 0;
}
