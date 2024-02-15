#include <iostream>
#include <vector>

std::vector<int> split(const std::string& str, const std::string& delimiter = "--->")
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


struct Node
{
    int value;
    Node* next;

    Node()
    : next(nullptr)
    {}

    Node(int nodeValue)
            : value(nodeValue), next(nullptr)
    {}

    Node(int nodeValue, Node* node)
            : value(nodeValue), next(node)
    {}

    static Node* createList(const std::string& str)
    {
        std::vector<int> numbers = split(str);

        Node* head = new Node();
        Node* current = head;
        for (const int num: numbers)
        {
            current->next = new Node(num);
            current = current->next;
        }
        return head;
    }

    static void printList(Node* head)
    {
        Node* it = head->next;
        while (it)
        {
            if (it->next != nullptr)
            {
                std::cout << it->value << "--->";
            } else
            {
                std::cout << it->value;
            }
            it = it->next;
        }
    }

    static void modify(Node* head)
    {

        Node* zero_it = nullptr;
        Node* it = head->next;
        while (it)
        {
            if (it->value == 0 && zero_it == nullptr)
            {
                zero_it = it;
            } else if (it->value != 0 && zero_it != nullptr)
            {
                std::swap(it->value, zero_it->value);
                zero_it = zero_it->next;
            }
            it = it->next;
        }
    }
};

int main()
{
    std::string buffer;
    std::cin >> buffer;

    Node* head = Node::createList(buffer);
    Node::modify(head);
    Node::printList(head);
}
