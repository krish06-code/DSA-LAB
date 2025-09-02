#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 2, 4, 5};
    vector<int> result; // with using space

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 2) {
            result.push_back(2);
            result.push_back(2);
        } else {
            result.push_back(arr[i]);
        }
    }

    for (int x : result) cout << x << " ";

    vector<int> arr = {1, 2, 3, 2, 4, 5}; // without using space
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        if (arr[i] == 2) {
            for (int j = n - 1; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            if (i + 1 < n) arr[i + 1] = 2;
            i++; 
        }
    }

    for (int x : arr) cout << x << " ";

    return 0;
}
