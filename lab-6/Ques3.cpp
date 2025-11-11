#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int sizeOfDoubly(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

int main() {
    Node* head = new Node{10, nullptr, nullptr};
    Node* second = new Node{20, head, nullptr};
    Node* third = new Node{30, second, nullptr};
    head->next = second;
    second->next = third;
    cout << "Size of Doubly Linked List: " << sizeOfDoubly(head);
    return 0;
}
