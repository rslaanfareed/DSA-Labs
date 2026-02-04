#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;


bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch=='^';
}


int operate(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return pow(a,b);
    }
    return 0;
}


int evaluatePostfix(string expr) {
    stack<int> st;

    for (char ch : expr) {
        if (isdigit(ch)) {
            st.push(ch - '0');
        }
        else if (isOperator(ch)) {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result = operate(a, b, ch);
            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string postfix;
    cout<<"Enter postfix expression"<<endl;
    cin>>postfix;
    cout << "Result = " << evaluatePostfix(postfix) << endl;
    return 0;
}

