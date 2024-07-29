#include <iostream>
#include <stack>
#include <algorithm>  // for reverse
using namespace std;

// Function to return precedence of operators
int precedence(char ch) {
    if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return -1; // for non-operator characters
}

// Function to convert infix to postfix
string infixtopostfix(string str) {
    stack<char> st;
    string output;
    for (int i = 0; i < str.size(); i++) {
        // If the scanned character is an operand, add it to output string.
        if (isalpha(str[i])) {
            output = output + str[i];
        }
        // If the scanned character is an '(', push it to the stack.
        else if (str[i] == '(') {
            st.push(str[i]);
        }
        // If the scanned character is an ')', pop and output from the stack until an '(' is encountered.
        else if (str[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                output = output + st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
                st.pop(); // remove '(' from stack
        }
        // If an operator is scanned
        else {
            while (!st.empty() && precedence(str[i]) <= precedence(st.top())) {
                output = output + st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    // Pop all the operators from the stack
    while (!st.empty()) {
        output = output + st.top();
        st.pop();
    }

    return output;
}

// Function to convert infix to prefix
string infixtoprefix(string str) {
    reverse(str.begin(), str.end());
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(')
            str[i] = ')';
        else if (str[i] == ')')
            str[i] = '(';
    }
    string new_str = infixtopostfix(str);
    reverse(new_str.begin(), new_str.end());
    return new_str;
}

int main() {
    string notation = "A+B-C+D";
    string ans = infixtoprefix(notation);
    cout << "Prefix notation: " << ans << endl;
    return 0;
}
