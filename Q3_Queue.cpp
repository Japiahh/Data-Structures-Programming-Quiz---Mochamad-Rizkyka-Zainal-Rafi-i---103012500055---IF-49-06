#include <iostream>
using namespace std;
const int MAX = 5;
struct Queue {
    int data[MAX];
    int front, rear;
};
void createQueue(Queue &Q) {
    Q.front = -1;
    Q.rear = -1;
}
bool isFull(Queue Q) {
    return Q.rear == MAX - 1;
}
bool isEmpty(Queue Q) {
    return Q.front == -1 || Q.front > Q.rear;
}
void enqueue(Queue &Q, int value) {
    if (isFull(Q)) {
        cout << "Queue Overflow! Cannot enqueue " << value << endl;
    } else {
        if (Q.front == -1) {
            Q.front = 0;
        }
        Q.rear = Q.rear + 1;
        Q.data[Q.rear] = value;
        cout << value << " inserted successfully." << endl;
    }
}
void dequeue(Queue &Q) {
    int value;
    if (isEmpty(Q)) {
        cout << "Queue Underflow! Queue is empty." << endl;
    } else {
        value = Q.data[Q.front];
        Q.front =  Q.front + 1;
        if (Q.front > Q.rear) {
            Q.front = -1;
            Q.rear = -1;
        }
        cout << value << " removed successfully." << endl;
    }
}

void front(Queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Front element: " << Q.data[Q.front] << endl;
    }
}

void display(Queue Q) {
    int i;
    if (isEmpty(Q)) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue: ";
        i = Q.front;
        while (i <= Q.rear) {
            cout << Q.data[i] << " ";
            i = i + 1;
        }
        cout << endl;
    }
}

int main() {
    Queue Q;
    int choice;
    int value;
    createQueue(Q);
    choice = 0;
    while (choice != 5) {
        cout << "\n===== QUEUE MENU =====" << endl;
        cout << "1. Enqueue  2. Dequeue" << endl;
        cout << "3. Front  4. Display  5. Exit" << endl;
        cout << endl;
        if (!isEmpty(Q)) {
            display(Q);
        }
        cout << "Choose operation: ";
        if (cin >> choice) {
            if (choice == 1) {
                cout << "Enter value: ";
                cin >> value;
                enqueue(Q, value);
            } else if (choice == 2) {
                dequeue(Q);
            } else if (choice == 3) {
                front(Q);
            } else if (choice == 4) {
                display(Q);
            } else if (choice != 5) {
                cout << "Invalid choice." << endl;
            }
        } else {
            choice = 5;
        }
    }
}
