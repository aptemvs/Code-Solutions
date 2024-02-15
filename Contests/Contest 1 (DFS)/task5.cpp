#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

int main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    std::cin >> n >> m >> k;
    std::vector<std::vector<std::pair<int, int>>> matrix(n + 1);

    int u = 0;
    int v = 0;
    int c = 0;
    for (int i = 0; i < m; i++)
    {
        std::cin >> u >> v >> c;
        matrix[u].push_back({v, c});
    }

    int l;
    std::cin >> l;
    std::vector<int> instructions(l);

    for (int i = 0; i < l; i++)
    {
        std::cin >> instructions[i];
    }

    int s;
    std::cin >> s;

    std::set<int> current_rooms = {s};
    bool hang = false;

    for (int i = 0; i < l; i++)
    {
        std::set<int> next_rooms;
        hang = true;

        for (int room: current_rooms)
        {
            for (auto& corridor: matrix[room])
            {
                if (corridor.second == instructions[i])
                {
                    next_rooms.insert(corridor.first);
                    hang = false;
                }
            }
        }

        if (hang)
        {
            std::cout << "Hangs" << '\n';
            return 0;
        }

        current_rooms = next_rooms;
    }

    std::cout << "OK" << '\n';
    std::cout << current_rooms.size() << '\n';
    for (int room: current_rooms)
    {
        std::cout << room << " ";
    }
    std::cout << '\n';

    return 0;
}
