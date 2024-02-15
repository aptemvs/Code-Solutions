#include <iostream>

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
        }

        int two_steps_back = 1;
        int one_step_back = 2;
        int current_step = 0;

        for (int i = 2; i < n; i++)
        {
            current_step = two_steps_back + one_step_back;

            two_steps_back = one_step_back;
            one_step_back = current_step;
        }

        return current_step;
    }
};
