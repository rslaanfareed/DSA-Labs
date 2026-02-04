#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* root = NULL;


void insertion(int x) {
    Node* n = new Node(x);

    if (root == NULL) {
        root = n;
        return;
    }

    Node* curr = root;
    Node* parent = NULL;

    while (curr != NULL) {
        parent = curr;
        if (x < curr->data)
            curr = curr->left;
        else if (x > curr->data)
            curr = curr->right;
        else
            return;
    }

    if (x < parent->data)
        parent->left = n;
    else
        parent->right = n;
}


bool searching(int x) {
    Node* curr = root;

    while (curr != NULL) {
        if (curr->data == x)
            return true;
        else if (x < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }
    return false;
}


void Preorder() {
    if (root == NULL)
        return;

    stack<Node*> s;
    s.push(root);

    cout << "Preorder Traversal: ";

    while (!s.empty()) {
        Node* curr = s.top();
        s.pop();

        cout << curr->data << " ";

        if (curr->right != NULL)
            s.push(curr->right);
        if (curr->left != NULL)
            s.push(curr->left);
    }
    cout << endl;
}


void deletion(int x) {
    Node* curr = root;
    Node* parent = NULL;

    while (curr != NULL && curr->data != x) {
        parent = curr;
        if (x < curr->data)
            curr = curr->left;
        else
            curr = curr->right;
    }

    if (curr == NULL)
        return;


    if (curr->left == NULL && curr->right == NULL) {
        if (curr == root)
            root = NULL;
        else if (parent->left == curr)
            parent->left = NULL;
        else
            parent->right = NULL;
        delete curr;
    }

    else if (curr->left == NULL || curr->right == NULL) {
        Node* child = (curr->left != NULL) ? curr->left : curr->right;

        if (curr == root)
            root = child;
        else if (parent->left == curr)
            parent->left = child;
        else
            parent->right = child;

        delete curr;
    }

    else {
        Node* sucParent = curr;
        Node* successor = curr->right;

        while (successor->left != NULL) {
            sucParent = successor;
            successor = successor->left;
        }

        curr->data = successor->data;

        if (sucParent->left == successor)
            sucParent->left = successor->right;
        else
            sucParent->right = successor->right;

        delete successor;
    }
}

int main() {
    cout << "Binary Search Tree" << endl;

    insertion(8);
    insertion(3);
    insertion(1);
    insertion(6);
    insertion(7);
    insertion(10);
    insertion(14);
    insertion(4);

    cout<<"searching 3"<<endl;
    cout << "searching output: " << searching(3) << endl;
    cout << endl;

    Preorder();

    cout << "deleting 4" << endl;
    deletion(4);
    Preorder();

    cout << "deleting 8" << endl;
    deletion(8);
    Preorder();

    return 0;
}
