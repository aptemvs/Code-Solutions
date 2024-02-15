#include <iostream>
#include <utility>
#include <vector>

std::vector<int> split(const std::string& str, const std::string& delimiter = "|")
{
    size_t start = 0;
    size_t end = 0;
    size_t delimiter_size = delimiter.size();
    std::string buffer;
    std::vector<int> result;

    while ((end = str.find(delimiter, start)) != std::string::npos)
    {
        buffer = str.substr(start, end - start);
        start = end + delimiter_size;
        result.push_back(std::stoi(buffer));
    }
    result.push_back(std::stoi(str.substr(start)));

    return result;
}

class MinHeap
{

public:
    explicit MinHeap(std::vector<int> user_heap, int div)
            : heap(std::move(user_heap)), divisor(div)
    {}

public:
    void printKpaths()
    {
        std::vector<int> path;
        printDivisiblePath(path, 0);

        if (!flag)
        {
            std::cout << "-1" << '\n';
        }
    }

private:

    void printVector(const std::vector<int>& vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            if (i == vec.size() - 1)
            {
                std::cout << vec[i] << '\n';;
            } else
            {
                std::cout << vec[i] << "--->";
            }
        }
    }

    void printDivisiblePath(std::vector<int>& path, int index)
    {
        if (heap.empty())
            return;

        if (heap.size() == 1)
        {
            std::cout << heap[0];
            flag = true;
            return;
        }

        if (index >= heap.size())
            return;

        path.push_back(heap[index]);

        int index_first_child = 2 * index + 1;
        int index_second_child = 2 * index + 2;

        if (index_first_child <= heap.size())
            printDivisiblePath(path, index_first_child);

        if (index_second_child <= heap.size())
            printDivisiblePath(path, index_second_child);

        int sum = 0;
        for (int value : path)
        {
            sum += value;
        }

        if (sum % divisor == 0 && index_first_child > heap.size())
        {
            printVector(path);
            flag = true;
        }

        path.pop_back();
    }

private:
    int divisor;
    std::vector<int> heap;
    bool flag = false;
};

int main()
{
    int divisor;
    std::cin >> divisor;

    std::string heap_string;
    std::cin >> heap_string;

    std::vector heap_vec = split(heap_string);

    MinHeap heap(heap_vec, divisor);

    heap.printKpaths();

    return 0;
}