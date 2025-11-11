#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q;
public:
    void push(int x) {
        q.push(x);
        for (int i = 0; i < q.size()-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    void pop() { if (!q.empty()) q.pop(); }
    int top() { return q.empty() ? -1 : q.front(); }
    bool empty() { return q.empty(); }
};

int main() {
    Stack st;
    st.push(10);
    st.push(20);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
}
