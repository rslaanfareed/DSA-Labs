#include <iostream>
using namespace std;

bool syntaxChecking(char infix[], int ub, char validity[]){

    int top = -1;        // this is your "validity array" stack
    bool valid = true;

    // 1. scan the expression from left to right
    for(int i = 0; i <= ub; i++){

        // i. if symbol is left parenthesis then push it onto stack
        if(infix[i] == '(' || infix[i] == '{' || infix[i] == '['){
            validity[++top] = infix[i];
        }

        // ii. if symbol is right parenthesis
        else if(infix[i] == ')' || infix[i] == '}' || infix[i] == ']'){

            // a. check if stack is empty
            if(top == -1){
                valid = false;
                break;
            }

            // b. pop and compare
            char popped = validity[top--];

            // if popped does NOT match scanned symbol → invalid
            if((popped=='(' && infix[i] != ')') ||
               (popped=='{' && infix[i] != '}') ||
               (popped=='[' && infix[i] != ']')){
                valid = false;
                break;
            }
        }
    }

    // 2. after scanning all symbols, if stack NOT empty → invalid
    if(top != -1){
        valid = false;
    }

    // 3. return
    return valid;
}

int main(){
    char infix[100], validity[100];
while(true){
    cout << "Enter expression: ";
    cin >> infix;

    int ub = 0;
    while(infix[ub] != '\0') ub++;
    ub--;

    if(syntaxChecking(infix, ub, validity))
        cout << "Expression is VALID\n";
    else
        cout << "Expression is NOT VALID\n";
}
    return 0;
}
