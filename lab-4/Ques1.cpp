#include <iostream>
using namespace std;
#define SIZE 5

class Queue {
    int arr[SIZE], front, rear;
public:
    Queue() { front = -1; rear = -1; }
    bool isEmpty() { return front == -1; }
    bool isFull() { return (rear + 1) % SIZE == front; }
    void enqueue(int x) {
        if (isFull()) { cout << "Queue Full\n"; return; }
        if (isEmpty()) front = rear = 0;
        else rear = (rear + 1) % SIZE;
        arr[rear] = x;
    }
    void dequeue() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }
    void display() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
    void peek() {
        if (!isEmpty()) cout << arr[front] << endl;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();
    q.dequeue();
    q.display();
    q.peek();
}
