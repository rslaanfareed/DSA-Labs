#include <iostream>
#include <stack>
using namespace std;

string reverseString(string str) {
    stack<char> st;


    for (char c : str)
        st.push(c);


    int i = 0;
    while (!st.empty()) {
        str[i++] = st.top();
        st.pop();
    }
    return str;
}

int main() {
    string str;
    while(true){
    cout<<"Enter String to reverse"<<endl;
    cin>>str;
    if(str=="exit") return 0;
    cout << "Original String: " << str << endl;

    string reversed = reverseString(str);
    cout << "Reversed String: " << reversed << endl;
}
}

