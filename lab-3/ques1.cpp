#include <iostream>
using namespace std;

#define SIZE 5

int stack[SIZE];
int top = -1;

void push(int val) {
    if (top == SIZE - 1) {
        cout << "Stack is Full" << endl;
    } else {
        top++;
        stack[top] = val;
        cout << val << " pushed" << endl;
    }
}

void pop() {
    if (top == -1) {
        cout << "Stack is Empty" << endl;
    } else {
        cout << stack[top] << " popped" << endl;
        top--;
    }
}

void peek() {
    if (top == -1) {
        cout << "Stack is Empty" << endl;
    } else {
        cout << "Top element: " << stack[top] << endl;
    }
}

void display() {
    if (top == -1) {
        cout << "Stack is Empty" << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

void isEmpty() {
    if (top == -1) cout << "Stack is Empty" << endl;
    else cout << "Stack is not Empty" << endl;
}

void isFull() {
    if (top == SIZE - 1) cout << "Stack is Full" << endl;
    else cout << "Stack is not Full" << endl;
}

int main() {
    int choice, val;
     push(10);
    push(20);
    push(30);
    display();
    peek();
    pop();
    display();
    isEmpty();
    isFull();
    
    return 0;
}
