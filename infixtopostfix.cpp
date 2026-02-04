#include <iostream>
#include <stack>
#include <string>
using namespace std;

string infixToPostfix(string infix) {

    //add '(' at top of stack and ')' at end
    stack<char> st;
    st.push('(');
    infix += ')';

    string postfix = "";

    //scan from left to right
    for (int i = 0; i < infix.length(); i++) {

        char ch = infix[i];

        // Step 3: if '(' push
        if (ch == '(') {
            st.push(ch);
        }

        //if operand then add to postfix
        else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }

        //if operator encountered
        else if (ch == '+' || ch == '-') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }

        else if (ch == '*' || ch == '/') {
            while (!st.empty() && (st.top() == '*' || st.top() == '/' || st.top() == '^')) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }

        else if (ch == '^') {
            while (!st.empty() && st.top() == '^') {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }

        //if ')' pop until '('
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
    }


    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    cout << "Postfix: " << infixToPostfix(infix) << endl;
    return 0;
}
