#include <bits/stdc++.h>
using namespace std;
int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int k = 2, n = sizeof(arr) / sizeof(arr[0]), count = 0;
    sort(arr, arr + n);
    int i = 0, j = 1;
    while (j < n) {
        int diff = arr[j] - arr[i];
        if (diff == k) {
            count++;
            i++; j++;
        } else if (diff > k) i++;
        else j++;
        if (i == j) j++;
    }
    cout << count;
}
