#include <ostream>


template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
{
    out << "[";
    if (!vec.empty())
    {
        out << vec[0];
        for (size_t i = 1; i < vec.size(); ++i)
        {
            out << ", " << vec[i];
        }
    }
    out << "]";
    return out;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<std::vector<T>>& matrix)
{
    out << "[";
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        if (i != 0) out << "\n ";
        out << matrix[i];
    }
    out << "]";
    return out;
}