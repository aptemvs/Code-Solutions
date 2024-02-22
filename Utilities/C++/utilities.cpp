#include <ostream>
#include <vector>
#include <optional>
#include <stdexcept>



struct SearchAlgorithms
{
    struct BinarySearch
    {
        template<typename T>
        ssize_t binarySearch(const std::vector<T>& vec, T value,
                         std::optional<ssize_t> l = std::nullopt,
                         std::optional<ssize_t> r = std::nullopt)
        {
            ssize_t left = l.value_or(0);
            ssize_t right = r.value_or(vec.size() - 1);

            if (left > right || left < 0 || right >= vec.size())
            {
                throw std::invalid_argument("Invalid search bounds");
            }

            while (left <= right)
            {
                ssize_t mid = left + (right - left) / 2;

                if (vec[mid] == value)
                {
                    return mid;
                }
                else if (vec[mid] < value)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }

            return -1;
        }

    };
};

struct SortingAlgorithms
{
    struct MergeSort
    {
    private:
        template<typename T>
        std::vector<T> merge(const std::vector<T>& left, const std::vector<T>& right)
        {
            std::vector<T> result;
            auto itLeft = left.begin();
            auto itRight = right.begin();

            while (itLeft != left.end() && itRight != right.end())
            {
                if (*itLeft < *itRight)
                {
                    result.push_back(*itLeft++);
                }
                else
                {
                    result.push_back(*itRight++);
                }
            }

            result.insert(result.end(), itLeft, left.end());
            result.insert(result.end(), itRight, right.end());

            return result;
        }

    public:
        template<typename T>
        std::vector<T> mergeSort(const std::vector<T>& vec)
        {
            if (vec.size() <= 1)
            {
                return vec;
            }

            auto middle = vec.size() / 2;
            std::vector<T> left(vec.begin(), vec.begin() + middle);
            std::vector<T> right(vec.begin() + middle, vec.end());

            left = mergeSort(left);
            right = mergeSort(right);

            return merge(left, right);
        }
    };
};

struct Matrix
{
    struct MatrixOperatorOverload
    {
        template<typename T>
        friend std::ostream& operator<<(std::ostream& out, const std::vector<T>& vec)
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
        friend std::ostream& operator<<(std::ostream& out, const std::vector<std::vector<T>>& matrix)
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
    };
};