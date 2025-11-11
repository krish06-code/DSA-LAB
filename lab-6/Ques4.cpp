#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

bool isPalindrome(Node* head) {
    if (!head) return true;
    Node* tail = head;
    while (tail->next) tail = tail->next;
    while (head != tail && tail->next != head) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node* n1 = new Node{'a', nullptr, nullptr};
    Node* n2 = new Node{'b', n1, nullptr};
    Node* n3 = new Node{'c', n2, nullptr};
    Node* n4 = new Node{'b', n3, nullptr};
    Node* n5 = new Node{'a', n4, nullptr};
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    if (isPalindrome(n1))
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
    return 0;
}
