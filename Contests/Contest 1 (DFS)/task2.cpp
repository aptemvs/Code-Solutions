#include <iostream>
#include <vector>

void dfs(int v, const std::vector<std::vector<int>>& matrix, std::vector<bool>& visited, int& counter)
{
    visited[v] = true;
    counter++;
    for (int near: matrix[v])
    {
        if (!visited[near])
        {
            dfs(near, matrix, visited, counter);
        }
    }
}

int main()
{
    int counter = 0;
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }

    if (m != n - 1)
    {
        std::cout << "NO" << '\n';
        return 0;
    }

    std::vector<bool> visited(n, false);
    dfs(0, matrix, visited, counter);
    counter == n ? std::cout << "YES" : std::cout << "NO";

    return 0;
}