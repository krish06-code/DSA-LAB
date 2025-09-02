#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2, 1, 0};
    int low = 0, mid = 0, high = arr.size() - 1;
    while (mid <= high) {
        if (arr[mid] == 0) swap(arr[low++], arr[mid++]);
        else if (arr[mid] == 1) mid++;
        else swap(arr[mid], arr[high--]);
    }
    for (int x : arr) cout << x << " ";
}
