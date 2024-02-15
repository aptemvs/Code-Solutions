#include <iostream>
#include <vector>
#include <algorithm>

struct Edge
{
    int from, to, knowledge;
};

const int INF = 1e9;

std::string solve_maze(const int N, const int M, const std::vector<Edge>& doors)
{
    std::vector<int> knowledge(N, -INF);
    knowledge[0] = 0;

    for (int i = 0; i < N; ++i)
    {
        for (const auto& door: doors)
        {
            if (knowledge[door.from] > -INF)
            {
                knowledge[door.to] = std::max(knowledge[door.to], knowledge[door.from] + door.knowledge);
            }
        }
    }

    std::vector<bool> reachable_positive_cycle(N, false);
    for (int i = 0; i < N; ++i)
    {
        for (const auto& door: doors)
        {
            if (knowledge[door.from] > -INF)
            {
                int new_knowledge = knowledge[door.from] + door.knowledge;
                if (knowledge[door.to] < new_knowledge)
                {
                    knowledge[door.to] = new_knowledge;
                    reachable_positive_cycle[door.to] = true;
                }
                else if (reachable_positive_cycle[door.from])
                {
                    reachable_positive_cycle[door.to] = true;
                }
            }
        }
    }

    if (reachable_positive_cycle[N - 1])
    {
        return ":)";
    }
    else if (knowledge[N - 1] > -INF)
    {
        return std::to_string(knowledge[N - 1]);
    }
    else
    {
        return ":(";
    }
}

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<Edge> doors(M);
    for (int i = 0; i < M; ++i)
    {
        std::cin >> doors[i].from >> doors[i].to >> doors[i].knowledge;
        doors[i].from--;
        doors[i].to--;
    }

    std::string result = solve_maze(N, M, doors);
    std::cout << result << std::endl;

    return 0;
}