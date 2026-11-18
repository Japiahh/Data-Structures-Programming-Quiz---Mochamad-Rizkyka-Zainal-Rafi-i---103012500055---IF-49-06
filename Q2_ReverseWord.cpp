#include <iostream>
using namespace std;
const int MAX = 100;
struct Stack {
    char data[MAX];
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
void push(Stack &S, char c) {
    if (isFull(S)) {
        cout << "Stack Overflow!" << endl;
    } else {
        S.top++;
        S.data[S.top] = c;
    }
}
char pop(Stack &S) {
    char c;
    if (isEmpty(S)) {
        cout << "Stack Underflow!" << endl;
        return '\0';
    }
    c = S.data[S.top];
    S.top--;
    return c;
}
int main() {
    Stack S;
    char word[MAX];
    char reversedWord[MAX];
    int i, j;
    createStack(S);
    cout << "Enter a word: ";
    cin >> word;
    i = 0;
    while (word[i] != '\0') {
        push(S, word[i]);
        i = i + 1;
    }
    j = 0;
    while (!isEmpty(S)) {
        reversedWord[j] = pop(S);
        j = j + 1;
    }
    reversedWord[j] = '\0';
    cout << "\nOriginal word: " << word << endl;
    cout << "Reversed word: " << reversedWord << endl;
}
