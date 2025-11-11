#include <iostream>
#include <stack>
using namespace std;

int evaluatePostfix(string exp) {
    stack<int> st;
    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];
        if (c >= '0' && c <= '9') {
            st.push(c - '0');
        } else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            if (c == '+') st.push(val1 + val2);
            else if (c == '-') st.push(val1 - val2);
            else if (c == '*') st.push(val1 * val2);
            else if (c == '/') st.push(val1 / val2);
        }
    }
    return st.top();
}

int main() {
    string exp;
    cout << "Enter Postfix Expression: ";
    cin >> exp;
    cout << "Result: " << evaluatePostfix(exp);
    return 0;
}
