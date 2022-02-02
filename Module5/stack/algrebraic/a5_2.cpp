/*
student   : Jose Alfredo Martinez
instructor: Dave Harden
class     : CS 10C
date      : Jan 25, 2022
file name : a5_2.cpp


Do programming problem 6 from chapter 6 of the text.
   
    Use the pseudocode algorithm that evaluates postfix expressions given at the end of section 6.3.1
    and the pseudocode algorithm that converts an infix expression to postfix form given near the end
    of section 6.3.2. Use the STL stack class.

    The problem says to "Design and implement a class of infix calculators," but we will simply write
    a function named "evaluateInfix()" that evaluates infix expressions. It should have one string
    parameter and should return an int result. It should call a separate function named "infixToPostfix()"
    to convert the infix expression into a postfix expression, and then it should do the work of evaluating
    the resulting postfix expression. Then write a main() function to thoroughly test the function.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

/// <summary>
/// is character a decimal character '0'...'9'
/// </summary>
/// <param name="ch"></param>
/// <returns></returns>
bool isOperand( char ch ) {
    return ch >= '0' && ch <= '9';
}

/// <summary>
/// return true if +,-,*,/ else false
/// </summary>
/// <param name="ch"></param>
/// <returns></returns>
bool isOperator(char ch) {
    switch (ch)
    {
    case '+':
        return true;
    case '-':
        return true;
    case '*':
        return true;
    case '/':
        return true;
    default:
        return false;
        break;
    }
}

/// <summary>
/// pre: valid operation
/// post: operand1 op operand2
/// </summary>
/// <param name="operand1"></param>
/// <param name="op"></param>
/// <param name="operand2"></param>
/// <returns></returns>
int  performOperation(int operand1, char op, int operand2) {
    switch (op) {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        return operand1 / operand2;
    default:
        return 0;
        break;
    }
}
/// <summary>
/// pre:  ch is an operator
/// </summary>
/// <param name="ch"></param>
/// <returns></returns>
int precedence(char ch) {
    switch (ch)
    {
    case '+':
        return 0;
    case '-':
        return 0;
    case '*':
        return 1;
    case '/':
        return 1;
    default:
        return -1;
        break;
    }
}
/// <summary>
/// pre: simple infix expressions that consist of single-digit operands; the operators +, –, *, and /; and parentheses.
///  Assume that unary operators are illegal and that the expression contains no embedded spaces
/// post: 
///  @return a stack of string  that represents the postfix operation
/// </summary>
/// <param name="infix"></param>
/// <returns></returns>
string infixToPostfix( const string & infix) {
    string postfixExp = "";
    stack<char> aStack;

    for (size_t i = 0; i < infix.size(); i++) {
        char ch = infix[i];
        if (isOperand(ch)) { // Append operand to end of postfix expression—step 1
            postfixExp = postfixExp + ch;
        }
        else if (ch == '(') { // Save '(' on stack—step 2
            aStack.push(ch);
        }
        else if (isOperator(ch)) { // Process stack operators of greater precedence—step 3
            while (!aStack.empty() &&
                aStack.top() != '(' &&
                precedence(ch) <= precedence(aStack.top())) {
                postfixExp = postfixExp + aStack.top();
                aStack.pop();
            }
            aStack.push(ch); // Save the operator

        }
        else if (ch == ')') { // Pop stack until matching '(' —step 4
            while (aStack.top() != '(') {
                postfixExp = postfixExp + aStack.top();
                aStack.pop();
            }
            aStack.pop(); // Remove the open parenthesis
        }
    }
    
    // Append to postfixExp the operators remaining in the stack—step 5
    while ( !aStack.empty() ) {
        postfixExp = postfixExp + aStack.top();
        aStack.pop();
    }

    return postfixExp;
}

/// <summary>
/// pre: a valid postfix expression
/// post: 
///  @return the calculated value for the postfix expression.
/// </summary>
/// <param name="postfix"></param>
/// <returns></returns>
int evaluateInfix(const string& postfix) {
    stack<char> aStack;
    for (size_t i = 0; i < postfix.size(); i++) {
        char ch = postfix[i];
        if (isOperand(ch)) {
            aStack.push(ch);
        }
        else { // ch is an operator named op
        
            // load operands
            int operand2 = aStack.top() - '0';
            aStack.pop();
            int operand1 = aStack.top() - '0';
            aStack.pop();

            int result = performOperation(operand1, ch, operand2);

            // convert result back to character
            stringstream ss;
            ss << result;
            string stringResult = ss.str();
            aStack.push(stringResult[0]);
        }
    }
    // convert back to integer
    return aStack.top()-'0';
}
int main() {
    vector<string> infixs = { "1+(5-2)/2 + 2", "2*3-5*1", "9/3+4/2", "9/(3+4)/2" };
    for (size_t i = 0; i < infixs.size(); i++) {
        std::cout << "operation: " << infixs[i];
        string postfix = infixToPostfix(infixs[i]);
        int result1 = evaluateInfix(postfix);
        cout << " = " << result1 << endl;
    }
    

}

/*
 output

operation: 1+(5-2)/2 + 2 = 4
operation: 2*3-5*1 = 1
operation: 9/3+4/2 = 5
operation: 9/(3+4)/2 = 0
*/