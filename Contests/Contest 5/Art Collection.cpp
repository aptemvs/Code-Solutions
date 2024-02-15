#include <iostream>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <map>

class ArtCollection
{
public:
    void push(const std::string& painting)
    {
        gallery[painting];
        galleryTopAdd(0, painting);
    }

    void like(const std::string& painting)
    {
        galleryTopRemove(gallery[painting], painting);
        gallery[painting] += 1;
        galleryTopAdd(gallery[painting], painting);
    }

    void dislike(const std::string& painting)
    {
        galleryTopRemove(gallery[painting], painting);
        gallery[painting] -= 1;
        galleryTopAdd(gallery[painting], painting);
    }

    void top(int k)
    {
        auto it = galleryTop.end();
        while (k > 0)
        {
            auto paintingsSet = it->second;
            for (const auto& painting: paintingsSet)
            {
                if (k > 1)
                {
                    std::cout << painting << ',';
                    k--;
                } else if (k == 1)
                {
                    std::cout << painting << '\n';
                    return;
                }
            }
            it--;
        }
    }

private:
    void galleryTopRemove(int likes, const std::string& painting)
    {
        galleryTop[likes].erase(painting);

        if (galleryTop.empty())
            galleryTop.erase(likes);
    }

    void galleryTopAdd(int likes, const std::string& painting)
    {
        galleryTop[likes].insert(painting);
    }


private:
    std::unordered_map<std::string, int> gallery;
    std::map<int, std::unordered_set<std::string>> galleryTop;
};

int main()
{
    ArtCollection collection;
    std::string input = " ";

    while (true)
    {
        std::getline(std::cin, input);

        if (input == "q")
        {
            break;
        } else
        {
            std::string operation;
            std::string name;

            std::stringstream ss(input);
            ss >> operation >> name;

            if (operation == "push")
                collection.push(name);

            else if (operation == "like")
                collection.like(name);

            else if (operation == "dislike")
                collection.dislike(name);

            else if (operation == "top")
                collection.top(std::stoi(name));
        }
    }
    return 0;
}