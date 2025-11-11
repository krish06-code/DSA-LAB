#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int>& A) {
    int n = A.size();
    vector<int> ans(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= A[i]) {
            st.pop();
        }
        if (!st.empty()) ans[i] = st.top();
        st.push(A[i]);
    }

    return ans;
}


int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> ans = nextGreater(arr);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
