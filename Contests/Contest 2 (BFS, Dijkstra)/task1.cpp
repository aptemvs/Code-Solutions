#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
    int n = 0;
    std::cin >> n;

    int parent = 0;
    std::vector<std::vector<int>> tree(n + 1);
    for (int i = 2; i <= n; i++)
    {
        std::cin >> parent;
        tree[parent].push_back(i);
    }

    std::queue<std::pair<int, int>> queue;
    queue.push({1, 0});

    int max_distance = 0;
    std::vector<int> farthest_nodes;

    while (!queue.empty())
    {
        int node = queue.front().first;
        int distance = queue.front().second;
        queue.pop();

        if (distance > max_distance)
        {
            max_distance = distance;
            farthest_nodes.clear();
            farthest_nodes.push_back(node);
        }
        else if (distance == max_distance)
        {
            farthest_nodes.push_back(node);
        }

        for (int child: tree[node])
        {
            queue.push({child, distance + 1});
        }
    }

    std::sort(farthest_nodes.begin(), farthest_nodes.end());


    std::cout << max_distance << '\n';
    std::cout << farthest_nodes.size() << '\n';
    for (int node: farthest_nodes)
    {
        std::cout << node << " ";
    }
    std::cout << '\n';

    return 0;
}
