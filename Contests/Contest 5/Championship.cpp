#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> players(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> players[i];
    }

    std::pair<int, int> indexesFirstTeam;
    std::cin >> indexesFirstTeam.first >> indexesFirstTeam.second;

    int totalPowerFirstTeam = players[indexesFirstTeam.first] + players[indexesFirstTeam.second];

    // fill map {power, vec{indexes}}
    std::unordered_map<int, std::vector<int>> playersMap;
    for (int i = 0; i < n; i++)
    {
        bool indexesBusy = (i == indexesFirstTeam.first || i == indexesFirstTeam.second);

        if (!indexesBusy)
            playersMap[players[i]].push_back(i);
    }

    for (const auto& p3: playersMap)
    {
        int toGather = totalPowerFirstTeam - p3.first;
        auto p4 = playersMap.find(toGather);

        if (p4 != playersMap.end())
        {
            int p3Ans = p3.second.at(0);
            int p4Ans = p4->second.at(0);

            if (p3Ans < p4Ans)
                std::cout << p3Ans << ' ' << p4Ans;
            else
                std::cout << p4Ans << ' ' << p3Ans;
            break;
        }
    }
    return 0;
}