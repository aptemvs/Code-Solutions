#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class DisjointSets
{
public:
    DisjointSets(int n)
    {
        reset(n);
    }

    void reset(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
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

    bool join(int x, int y)
    {
        int root_x = find(x);
        int root_y = find(y);

        if (root_x == root_y)
        {
            return false;
        }

        if (rank[root_x] > rank[root_y])
        {
            parent[root_y] = root_x;
        }
        else
        {
            parent[root_x] = root_y;
            if (rank[root_x] == rank[root_y])
            {
                ++rank[root_y];
            }
        }

        return true;
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line, command;
    int n, j, k;

    DisjointSets ds(0);

    while (std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        iss >> command;

        if (command == "RESET")
        {
            iss >> n;
            ds.reset(n);
            std::cout << "RESET DONE" << '\n';
        }
        else if (command == "JOIN")
        {
            iss >> j >> k;
            if (!ds.join(j, k))
            {
                std::cout << "ALREADY " << j << " " << k << '\n';
            }
        }
        else if (command == "CHECK")
        {
            iss >> j >> k;
            if (ds.find(j) == ds.find(k))
            {
                std::cout << "YES" << '\n';
            }
            else
            {
                std::cout << "NO" << '\n';
            }
        }
    }

    return 0;
}
