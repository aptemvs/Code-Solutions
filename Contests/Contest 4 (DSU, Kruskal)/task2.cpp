#include <iostream>
#include <vector>
#include <algorithm>

struct Edge
{
    int x, y;
    int index;
};

bool edge_comparator(const Edge& a, const Edge& b)
{
    return a.index < b.index;
}

int find_parent(int x, std::vector<int>& parents)
{
    if (parents[x] != x)
        parents[x] = find_parent(parents[x], parents);
    return parents[x];
}

void union_set(int x, int y, std::vector<int>& parents, std::vector<int>& ranks)
{
    int root_x = find_parent(x, parents);
    int root_y = find_parent(y, parents);

    if (root_x != root_y)
    {
        if (ranks[root_x] > ranks[root_y])
        {
            parents[root_y] = root_x;
        }
        else
        {
            parents[root_x] = root_y;
            if (ranks[root_x] == ranks[root_y])
                ranks[root_y]++;
        }
    }
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    std::vector<Edge> edges(M);
    for (int i = 0; i < M; ++i)
    {
        std::cin >> edges[i].x >> edges[i].y;
        edges[i].index = i;
    }

    std::sort(edges.begin(), edges.end(), edge_comparator);

    std::vector<int> parents(N + 1);
    std::vector<int> ranks(N + 1, 0);
    for (int i = 1; i <= N; ++i)
    {
        parents[i] = i;
    }

    int bridges = 0;
    int connected_components = N;
    for (const auto& edge: edges)
    {
        if (find_parent(edge.x, parents) != find_parent(edge.y, parents))
        {
            union_set(edge.x, edge.y, parents, ranks);
            connected_components--;

            if (connected_components == 1)
            {
                bridges = edge.index + 1;
                break;
            }
        }
    }

    std::cout << bridges << '\n';

    return 0;
}
