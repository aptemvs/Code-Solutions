#include <iostream>
#include <vector>

size_t max(const std::vector<std::string>& vec)
{
    size_t maximum = 0;
    for (const std::string& value: vec)
    {
        maximum = std::max(maximum, value.size());
    }
    return maximum;
}

void changeTo(std::vector<std::string>& vec)
{
    for (std::string& str: vec)
    {
        if (str[1] == 'B')
        {
            str[1] = 'A';
        } else if (str[1] == 'P')
        {
            str[1] = 'B';
        } else if (str[1] == 'G')
        {
            str[1] = 'C';
        } else if (str[1] == 'S')
        {
            str[1] = 'D';
        }
    }
}

void changeFrom(std::vector<std::string>& vec)
{
    for (std::string& str: vec)
    {
        if (str[1] == 'A')
        {
            str[1] = 'B';
        } else if (str[1] == 'B')
        {
            str[1] = 'P';
        } else if (str[1] == 'C')
        {
            str[1] = 'G';
        } else if (str[1] == 'D')
        {
            str[1] = 'S';
        }
    }
}


void countSort(std::vector<std::string>& data, size_t index)
{
    std::vector<int> count(256, 0);
    for (const std::string& value: data)
    {
        if (index < value.size())
        {
            count[value[index]]++;
        } else
        {
            count[0]++;
        }
    }

    for (int i = 1; i < count.size(); i++)
    {
        count[i] += count[i - 1];
    }

    std::vector<std::string> result(data.size());
    for (auto it = data.rbegin(); it != data.rend(); it++)
    {
        const std::string& value = *it;
        if (index < value.size())
        {
            result[--count[value[index]]] = value;
        } else
        {
            result[--count[0]] = value;
        }
    }
    std::swap(data, result);
}

void radixSort(std::vector<std::string>& data)
{
    changeTo(data);
    for (int pos = max(data) - 1; pos >= 0; pos--)
    {
        countSort(data, pos);
    }
    changeFrom(data);
}

int main()
{
    int n;
    std::cin >> n;

    std::string buffer;
    std::vector<std::string> vec;
    for (int i = 0; i < n; i++)
    {
        std::cin >> buffer;
        vec.push_back(buffer);
    }

    radixSort(vec);

    for (const std::string& str: vec)
    {
        std::cout << str << '\n';
    }

    return 0;
}