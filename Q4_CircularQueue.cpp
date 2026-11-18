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
    return (Q.rear + 1) % MAX == Q.front;
}
bool isEmpty(Queue Q) {
    return Q.front == -1;
}
void enqueue(Queue &Q, int value) {
    if (isFull(Q)) {
        cout << "Queue Overflow! Cannot enqueue " << value << endl;
    } else {
        if (isEmpty(Q)) {
            Q.front = 0;
            Q.rear = 0;
        } else {
            Q.rear = (Q.rear + 1) % MAX;
        }
        Q.data[Q.rear] = value;
    }
}
int dequeue(Queue &Q) {
    int value;
    if (isEmpty(Q)) {
        cout << "Queue Underflow! Queue is empty." << endl;
        return -1;
    }
    value = Q.data[Q.front];
    if (Q.front == Q.rear) {
        Q.front = -1;
        Q.rear = -1;
    } else {
        Q.front = (Q.front + 1) % MAX;
    }
    return value;
}
void display(Queue Q) {
    int i;
    bool done;
    if (isEmpty(Q)) {
        cout << "Queue is empty." << endl;
    } else {
        cout << "Queue: ";
        i = Q.front;
        done = false;
        while (!done) {
            cout << Q.data[i];
            if (i == Q.rear) {
                done = true;
            } else {
                cout << " ";
                i = (i + 1) % MAX;
            }
        }
        cout << endl;
    }
}
int main() {
    Queue Q;
    createQueue(Q);
    enqueue(Q, 10);
    enqueue(Q, 20);
    enqueue(Q, 30);
    enqueue(Q, 40);
    enqueue(Q, 50);
    dequeue(Q);
    dequeue(Q);
    enqueue(Q, 60);
    enqueue(Q, 70);
    display(Q);
}
