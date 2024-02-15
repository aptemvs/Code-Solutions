#include <iostream>
#include <sstream>
#include <unordered_map>

class LotteryBox
{
public:
    bool insert(const std::string player)
    {
        if (!isInMap(player))
        {
            _players[player];
            return true;
        }
        return false;
    }

    bool remove(const std::string player)
    {
        if (isInMap(player))
        {
            _players.erase(player);
            return true;
        }
        return false;
    }

    std::string takeWinner() const
    {
        return _players.empty() ? "0" : _players.begin()->first;
    }

private:
    bool isInMap(const std::string player) const
    {
        auto possiblePlayer = _players.find(player);

        if (possiblePlayer != _players.end())
            return true;

        return false;
    }

private:
    std::unordered_map<std::string, int> _players;
};

void defineOperationWithName(const std::string& input, std::string& operation, std::string& name)
{
    std::stringstream ss(input);
    ss >> operation >> name;
}

int main()
{
    LotteryBox box;
    std::string input = " ";

    std::cout << std::boolalpha; // to print false, not 0;

    while (true)
    {
        std::getline(std::cin, input);

        if (input == "q")
            break;
        else if (input == "?")
            std::cout << box.takeWinner() << '\n';
        else
        {
            std::string operation;
            std::string name;
            defineOperationWithName(input, operation, name);

            if (operation == "+")
                std::cout << box.insert(name) << '\n';

            else if (operation == "-")
                std::cout << box.remove(name) << '\n';
        }
    }
    return 0;
}