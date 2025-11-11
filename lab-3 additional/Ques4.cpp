#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    stack<pair<int,int>> st;
    vector<int> ans(n, 0);
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top().first < temperatures[i]) {
            int prevIndex = st.top().second;
            st.pop();
            ans[prevIndex] = i - prevIndex;
        }
        st.push({temperatures[i], i});
    }
    return ans;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);

    for(int i =0;i<temperatures.size();i++){
        cout<<temperatures[i]<<" ";
    }

    return 0;
}
