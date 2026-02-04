#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char c) {
    if (c=='+' || c=='-') return 1;
    if (c=='*' || c=='/') return 2;
    if (c=='^') return 3;
    return 0;
}

bool rightAssoc(char c) {
    return c=='^';
}

bool isOp(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}

string infixToPostfix(string s) {
    stack<char> st;
    string out;
    st.push('(');
    s += ')';

    for (char c : s) {
        if (c=='(') st.push(c);
        else if (isalnum(c)) out += c;
        else if (isOp(c)) {
            while (!st.empty() && isOp(st.top())) {
                char t = st.top();
                bool h = prec(t) > prec(c);
                bool eqL = prec(t)==prec(c) && !rightAssoc(c);
                if (h || eqL) {
                    out += t;
                    st.pop();
                } else break;
            }
            st.push(c);
        }
        else if (c==')') {
            while (!st.empty() && st.top()!='(') {
                out += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
    }
    return out;
}

int main() {
    while(true){
    string exp;
    cout<<"Enter expression"<<endl;
    cin>>exp;
    cout << infixToPostfix(exp)<<endl;
    }
}
