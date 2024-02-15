class Solution
{
public:
    bool isValid(const std::string& s)
    {
        std::stack<char> leftBrackets;

        for (const char& bracket: s)
        {
            if (bracket == '(' || bracket == '{' || bracket == '[')
            {
                leftBrackets.push(bracket);
            } else
            {
                if (leftBrackets.empty())
                    return false;

                if (leftBrackets.top() != '(' && bracket == ')')
                    return false;

                if (leftBrackets.top() != '{' && bracket == '}')
                    return false;

                if (leftBrackets.top() != '[' && bracket == ']')
                    return false;

                leftBrackets.pop();
            }
        }
        if (leftBrackets.empty())
            return true;
        else
            return false;
    }
};