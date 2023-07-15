#include <string>

using namespace std;

class ExpressionManager {
public:
    static string infixToPostfix(const string& expression);
    static bool isBalanced(const string& expression);
};