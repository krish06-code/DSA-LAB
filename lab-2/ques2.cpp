#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 100};  
    int n = sizeof(arr) / sizeof(arr[0]);
    int cnt = 0;
    bool flag = true;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                cnt++;
                flag = false;
            }
        }
        if (flag == true) break;
        flag = true;  
    }

    cout << "The number of times loop runs is = " << cnt << endl;

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
