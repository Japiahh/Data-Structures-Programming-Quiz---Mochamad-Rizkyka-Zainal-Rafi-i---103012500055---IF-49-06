#include <iostream>
using namespace std;
const int MAX = 5;
struct Stack {
    int data[MAX];
    int top;
};
void createStack(Stack &S) {
    S.top = -1;
}
bool isFull(Stack S) {
    return S.top == MAX - 1;
}
bool isEmpty(Stack S) {
    return S.top == -1;
}
void push(Stack &S, int value) {
    if (isFull(S)) {
        cout << "Stack Overflow! Cannot push " << value << endl;
    } else {
        S.top++;
        S.data[S.top] = value;
        cout << value << " inserted successfully." << endl;
    }
}
void pop(Stack &S) {
    int value;
    if (isEmpty(S)) {
        cout << "Stack Underflow! Stack is empty." << endl;
    } else {
        value = S.data[S.top];
        S.top--;
        cout << value << " removed successfully." << endl;
    }
}
void peek(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Top element: " << S.data[S.top] << endl;
    }
}
void display(Stack S) {
    int i;

    if (isEmpty(S)) {
        cout << "Stack is empty." << endl;
    } else {
        cout << "Stack: ";
        i = S.top;
        while (i >= 0) {
            cout << S.data[i] << " ";
            i--;
        }
        cout << endl;
    }
}
int main() {
    Stack S;
    int choice;
    int value;

    createStack(S);
    choice = 0;

    while (choice != 5) {
        cout << "\n===== STACK MENU =====" << endl;
        cout << "1. Push  2. Pop  3. Peek" << endl;
        cout << "4. Display  5. Exit" << endl;
        cout << "\nChoose operation: ";
        if (cin >> choice) {
            if (choice == 1) {
                cout << "Enter value: ";
                cin >> value;
                push(S, value);
            } else if (choice == 2) {
                pop(S);
            } else if (choice == 3) {
                peek(S);
            } else if (choice == 4) {
                display(S);
            } else if (choice != 5) {
                cout << "Invalid choice." << endl;
            }
        } else {
            choice = 5;
        }
    }
}
