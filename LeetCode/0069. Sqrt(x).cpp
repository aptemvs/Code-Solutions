class Solution
{
public:
    static int mySqrt(int x)
    {
        size_t initial_number = x;
        size_t answer = 1;

        size_t l = 0;
        size_t r = initial_number;
        size_t middle = 0;

        while (l <= r)
        {
            middle = (l + r) / 2;
            size_t current_number = middle * middle;
            if (current_number > initial_number)
            {
                r = middle - 1;
            } else if (current_number < initial_number)
            {
                l = middle + 1;
                answer = middle;
            } else if (current_number == initial_number)
            {
                return middle;
            }
        }
        return answer;
    }
};
