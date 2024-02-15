#include <algorithm>
#include <iostream>
#include <vector>

enum class States
{
    UNVISITED,
    CURRENT,
    VISITED
};

bool dfs(int v,
         const std::vector<std::vector<int>>& matrix,
         std::vector<States>& states,
         std::vector<int>& cycle,
         std::vector<int>& parent)
{
    states[v] = States::CURRENT;
    cycle.push_back(v);

    for (int near: matrix[v])
    {
        if (states[near] == States::UNVISITED)
        {
            parent[near] = v;
            if (dfs(near, matrix, states, cycle, parent))
            {
                return true;
            }
        }
        else if (states[near] == States::CURRENT)
        {
            parent[near] = v;
            int current = v;
            std::vector<int> tempCycle;
            while (current != near)
            {
                tempCycle.push_back(current);
                current = parent[current];
            }
            tempCycle.push_back(near);
            std::reverse(tempCycle.begin(), tempCycle.end());
            cycle = tempCycle;
            return true;
        }
    }

    states[v] = States::VISITED;
    cycle.pop_back();
    return false;
}

int main()
{
    int u = 0;
    int v = 0;
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n);
    for (int i = 0; i < m; i++)
    {
        std::cin >> u >> v;
        u--;
        v--;
        matrix[u].push_back(v);
    }

    std::vector<States> state(n, States::UNVISITED);
    std::vector<int> cycle;
    std::vector<int> parent(n, -1);

    for (int i = 0; i < n; i++)
    {
        if (state[i] == States::UNVISITED && dfs(i, matrix, state, cycle, parent))
        {
            std::cout << "YES" << '\n';
            for (int j = 0; j < cycle.size(); j++)
            {
                std::cout << cycle[j] + 1 << ' ';
            }
            std::cout << '\n';
            return 0;
        }
    }

    std::cout << "NO" << '\n';

    return 0;
}
