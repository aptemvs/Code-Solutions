#include <iostream>
#include <unordered_map>

std::string compare(const std::unordered_map<char, int>& letters1,
                    const std::unordered_map<char, int>& letters2)
{
    for (const std::pair<const char, int>& letterInMap1: letters1)
    {
        auto letterInMap2 = letters2.find(letterInMap1.first);

        if (!(letterInMap2 != letters2.end() && letterInMap1.second == letterInMap2->second))
            return "No";
    }
    return "Yes";
}

int main()
{
    std::unordered_map<char, int> letters1;
    std::unordered_map<char, int> letters2;

    std::string word1;
    std::string word2;

    std::getline(std::cin, word1);
    std::getline(std::cin, word2);

    for (const char letter : word1)
    {
        if (letter != ' ')
            letters1[tolower(letter)]++;
    }

    for (const char letter : word2)
    {
        if (letter != ' ')
            letters2[tolower(letter)]++;
    }

    std::cout << compare(letters1, letters2);

    return 0;
}