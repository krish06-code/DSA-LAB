#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 4, 5, 6};  
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = n - 1;
    int missing = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] != mid + 1 && arr[mid - 1] == mid) {
            missing = mid + 1;
            break;
        }
        else if (arr[mid] < mid + 1) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (missing == -1) {
        missing = low + 1;  
    }

    cout << "Missing number: " << missing << endl;

    return 0;
}
