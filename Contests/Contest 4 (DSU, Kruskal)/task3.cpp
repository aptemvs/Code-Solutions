#include <iostream>
#include <vector>

class UnionFind
{
public:
    UnionFind(int n) : parent(n), rank(n, 0)
    {
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

    void join(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY)
        {
            return;
        }

        if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootX] = rootY;
            if (rank[rootX] == rank[rootY])
            {
                ++rank[rootY];
            }
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

int main()
{
    int n, m;
    std::cin >> n >> m;

    UnionFind uf(n);
    std::vector<int> weightSum(n, 0);

    for (int i = 0; i < m; ++i)
    {
        int op;
        std::cin >> op;

        if (op == 1)
        {
            int x, y, w;
            std::cin >> x >> y >> w;
            --x;
            --y;
            int rootX = uf.find(x);
            int rootY = uf.find(y);

            if (rootX != rootY)
            {
                uf.join(x, y);
                int newRoot = uf.find(x);
                weightSum[newRoot] = weightSum[rootX] + weightSum[rootY] + w;
            }
            else
            {
                weightSum[rootX] += w;
            }
        }
        else if (op == 2)
        {
            int x;
            std::cin >> x;
            --x;
            int rootX = uf.find(x);
            std::cout << weightSum[rootX] << '\n';
        }
    }

    return 0;
}
