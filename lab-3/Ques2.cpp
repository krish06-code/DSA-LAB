#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "DataStructure";
    int n = s.length();
    
    vector<char> ans(n);   
    stack<char> st;
    
    for (int i = 0; i < n; i++) {
        st.push(s[i]);
    }
    
    for (int i = 0; i < n; i++) {
        ans[i] = st.top();    
        st.pop();
    }
    
    for (int i = 0; i < n; i++) {
        cout << ans[i];  
    }
    cout << endl;
    
    return 0;
}
