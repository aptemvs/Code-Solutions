#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

std::pair<int, int> dfs(int node,
                        int parent,
                        std::map<int, std::vector<int>>& graph)
{
    std::pair<int, int> max_depth(0, node);

    for (int near: graph[node])
    {
        if (near != parent)
        {
            std::pair<int, int> depth = dfs(near, node, graph);
            depth.first++;
            if (depth.first > max_depth.first)
            {
                max_depth = depth;
            }
        }
    }

    return max_depth;
}

int main()
{
    int n = 0;
    std::cin >> n;
    std::map<int, std::vector<int>> graph;
    for (int i = 1; i <= n; ++i)
    {
        graph[i] = std::vector<int>(0);
    }

    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        std::cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::pair<int, int> semi_step = dfs(1, -1, graph);
    std::pair<int, int> final = dfs(semi_step.second, -1, graph);
    std::cout << final.first + 1 << '\n';
    return 0;
}
