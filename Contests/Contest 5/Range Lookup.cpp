#include <iostream>
#include <vector>

int leftmostBS(const std::vector<int>& elements, int& target)
{
    int l = 0;
    int r = elements.size();
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (elements[mid] < target)
        {
            l = mid + 1;
        } else
        {
            r = mid;
        }
    }
    return l;
}

int rightmostBS(const std::vector<int>& elements, int& target)
{
    int l = 0;
    int r = elements.size();
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (elements[mid] > target)
        {
            r = mid;
        } else
        {
            l = mid + 1;
        }
    }
    return r - 1;
}

int main()
{
    int n;
    std::cin >> n;

    std::vector<int> elements(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> elements[i];
    }

    int target;
    std::cin >> target;

    std::cout << leftmostBS(elements, target) << ' ' << rightmostBS(elements, target);
}