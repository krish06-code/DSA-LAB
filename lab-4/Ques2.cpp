#include <iostream>
using namespace std;
#define SIZE 5

class CQueue {
    int arr[SIZE], front, rear, count;
public:
    CQueue() { front = 0; rear = -1; count = 0; }
    bool isEmpty() { return count == 0; }
    bool isFull() { return count == SIZE; }
    void enqueue(int x) {
        if (isFull()) { cout << "Queue Full\n"; return; }
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        count++;
    }
    void dequeue() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        front = (front + 1) % SIZE;
        count--;
    }
    void display() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        int i = front;
        for (int c = 0; c < count; c++) {
            cout << arr[i] << " ";
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
    void peek() {
        if (!isEmpty()) cout << arr[front] << endl;
    }
};

int main() {
    CQueue cq;
    cq.enqueue(5);
    cq.enqueue(15);
    cq.enqueue(25);
    cq.enqueue(35);
    cq.display();
    cq.dequeue();
    cq.display();
    cq.peek();
}
