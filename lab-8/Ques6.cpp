#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
    vector<int> h;

    void heapifyDown(int i) {
        int n = h.size();
        while (true) {
            int largest = i;
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            if (l < n && h[l] > h[largest]) largest = l;
            if (r < n && h[r] > h[largest]) largest = r;
            if (largest != i) {
                swap(h[i], h[largest]);
                i = largest;
            } else break;
        }
    }

public:
    void push(int x) {
        h.push_back(x);
        int i = h.size() - 1;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (h[p] < h[i]) {
                swap(h[p], h[i]);
                i = p;
            } else break;
        }
    }

    void pop() {
        if (h.empty()) return;
        h[0] = h.back();
        h.pop_back();
        if (!h.empty()) heapifyDown(0);
    }

    int top() {
        if (h.empty()) return -1;
        return h[0];
    }

    bool empty() {
        return h.empty();
    }

    int size() {
        return (int)h.size();
    }
};

int main() {
    MaxHeap pq;
    int choice, x;
    while (true) {
        cout << "1. Insert\n2. Get max\n3. Delete max\n4. Size\n5. Exit\n";
        cin >> choice;
        if (choice == 1) {
            cin >> x;
            pq.push(x);
        } else if (choice == 2) {
            if (pq.empty()) cout << "Empty\n";
            else cout << pq.top() << endl;
        } else if (choice == 3) {
            pq.pop();
        } else if (choice == 4) {
            cout << pq.size() << endl;
        } else if (choice == 5) {
            break;
        }
    }
    return 0;
}
