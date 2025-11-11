#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

int sizeOfCircular(Node* head) {
    if (!head) return 0;
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

int main() {
    Node* head = new Node{10, nullptr};
    Node* second = new Node{20, nullptr};
    Node* third = new Node{30, nullptr};
    head->next = second;
    second->next = third;
    third->next = head;
    cout << "Size of Circular Linked List: " << sizeOfCircular(head);
    return 0;
}
