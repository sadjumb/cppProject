#include <iostream>
#include <stack>

int main()
{
    std::stack<char> st;
    std::string str;
    std::cin >> str;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
            st.push(str[i]);
        else
        {
            if (st.empty())
            {
                std::cout << "no";
                return 0;
            }
            if (st.top() == '(' && str[i] == ')')
                st.pop();
            else if (st.top() == '[' && str[i] == ']')
                st.pop();
            else if (st.top() == '{' && str[i] == '}')
                st.pop();
            else
            {
                std::cout << "no";
                return 0;
            }
        }
    }
    if (st.empty())
        std::cout << "yes";
    else
        std::cout << "no";
    return 0;
}