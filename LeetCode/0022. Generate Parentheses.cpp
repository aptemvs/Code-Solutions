#include <vector>
#include <string>
#include <queue>

class Solution
{
public:

    struct State
    {
        std::string currentString;
        int openCount;
        int closeCount;
    };

    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> result;
        std::queue<State> queue;

        queue.push({"", 0, 0});

        while (!queue.empty())
        {
            State state = queue.front();
            queue.pop();

            if (state.currentString.length() == 2 * n)
            {
                result.push_back(state.currentString);
                continue;
            }

            if (state.openCount < n)
            {
                queue.push({state.currentString + "(", state.openCount + 1, state.closeCount});
            }

            if (state.closeCount < state.openCount)
            {
                queue.push({state.currentString + ")", state.openCount, state.closeCount + 1});
            }
        }

        return result;
    }
};