#include <iostream>
#include <vector>

void dfs(int v, std::vector<std::vector<int>>& matrix, std::vector<bool>& visited, int& counter)
{
    visited[v] = true;
    counter++;
    for (int i = 0; i < matrix[v].size(); i++)
    {
        if (matrix[v][i] == 1 && !visited[i])
        {
            dfs(i, matrix, visited, counter);
        }
    }
}

int main()
{
    int counter = 0;
    int n = 0;
    int s = 0;
    std::cin >> n >> s;
    s--;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }

    std::vector<bool> visited(n, false);

    dfs(s, matrix, visited, counter);

    std::cout << counter << '\n';
    return 0;
}