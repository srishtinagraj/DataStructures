#include <iostream>
#include <stack>
#include <string>

bool areParenthesesBalanced(const std::string& expression) {
    std::stack<char> charStack;

    for (char ch : expression) {
        switch (ch) {
            case '(':
            case '[':
            case '{':
                charStack.push(ch);
                break;
            case ')':
                if (charStack.empty() || charStack.top() != '(') {
                    return false;
                }
                charStack.pop();
                break;
            case ']':
                if (charStack.empty() || charStack.top() != '[') {
                    return false;
                }
                charStack.pop();
                break;
            case '}':
                if (charStack.empty() || charStack.top() != '{') {
                    return false;
                }
                charStack.pop();
                break;
            default:
                // Ignore non-parentheses characters
                break;
        }
    }

    return charStack.empty();
}

int main() {
    std::string expression = "[(a+b)*c)}";
    std::cout << std::boolalpha << areParenthesesBalanced(expression) << std::endl;
    return 0;
}
