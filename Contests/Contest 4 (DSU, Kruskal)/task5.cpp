#include <iostream>
#include <vector>
#include <algorithm>

struct Edge
{
    int src;
    int dest;
    int weight;
};

class DisjointSet
{
public:
    explicit DisjointSet(int n)
    {
        parent.resize(n);

        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void merge(int x, int y)
    {
        int x_root = find(x);
        int y_root = find(y);
        parent[y_root] = x_root;
    }

private:
    std::vector<int> parent;
};

bool compareEdges(Edge a, Edge b)
{
    return a.weight < b.weight;
}

long long kruskal(int n, std::vector<Edge>& edges, int& mstEdges)
{
    std::sort(edges.begin(), edges.end(), compareEdges);

    DisjointSet ds(n);
    long long mstWeight = 0;
    mstEdges = 0;

    for (const auto& edge: edges)
    {
        int src_root = ds.find(edge.src);
        int dest_root = ds.find(edge.dest);

        if (src_root != dest_root)
        {
            mstWeight += edge.weight;
            ds.merge(src_root, dest_root);
            mstEdges++;

            if (mstEdges == n - 1)
            {
                break;
            }
        }
    }

    return mstWeight;
}

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<Edge> edges(m);
    for (int i = 0; i < m; ++i)
    {
        std::cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int mstEdges;
    long long result = kruskal(n, edges, mstEdges);

    if (mstEdges != n - 1)
    {
        std::cout << "NON-CONNECTED" << '\n';
    }
    else
    {
        std::cout << result << '\n';
    }

    return 0;
}
