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

    static Node* merge(Node* lhs, Node* rhs)
    {
        if (!lhs)
        {
            return rhs;
        } else if (!rhs)
        {
            return lhs;
        }
        if (lhs->value <= rhs->value)
        {
            lhs->next = merge(lhs->next, rhs);
            return lhs;
        } else
        {
            rhs->next = merge(lhs, rhs->next);
            return rhs;
        }
    }

    static std::vector<Node*> getNnodes(int n)
    {
        std::string buffer;
        std::vector<Node*> nodes;

        for (int i = 0; i < n; i++)
        {
            std::cin >> buffer;
            Node* node = Node::createList(buffer);
            nodes.push_back(node);
        }

        return nodes;
    }
};


int main()
{
    int n;
    std::cin >> n;

    std::vector<Node*> nodes = Node::getNnodes(n);

    Node* head = nodes[0];

    for (int i = 1; i < n; i++)
    {
        nodes[0] = Node::merge(nodes[0], nodes[i]);
        head = head->next;
    }

    Node::printList(head);
}
