#include <iostream>
#include <vector>

void dfs(int v, const std::vector<std::vector<int>>& matrix, std::vector<int>& components, int component)
{
    components[v] = component;
    for (int near: matrix[v])
    {
        if (components[near] == 0)
        {
            dfs(near, matrix, components, component);
        }
    }
}

int main()
{
    int component_counter = 0;
    int a = 0;
    int b = 0;
    int n = 0;
    int m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n);
    for (int i = 0; i < m; i++)
    {
        std::cin >> a >> b;
        a--;
        b--;
        matrix[a].push_back(b);
        matrix[b].push_back(a);
    }


    std::vector<int> components(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (components[i] == 0)
        {
            component_counter++;
            dfs(i, matrix, components, component_counter);
        }
    }

    std::cout << component_counter << '\n';

    for (int elem: components)
    {
        std::cout << elem << ' ';
    }

    return 0;
}