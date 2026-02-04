#include <iostream>
#include <string>
using namespace std;

void reverseString(char reversed[], const string &s) {
    int n = 0;
    // compute length (or could use s.length())
    while (s[n] != '\0') ++n;

    // fill reversed[] from the end of s
    for (int i = 0; i < n; ++i) {
        reversed[i] = s[n - 1 - i];
    }

    // null-terminate the C-string
    reversed[n] = '\0';
}

int main() {
    string s;
    // read a full line
    getline(cin, s);

    // make sure reversed buffer is large enough
    char reversed[1000];  // increase if you need longer strings

    reverseString(reversed, s);

    cout << reversed << '\n';
    return 0;
}
