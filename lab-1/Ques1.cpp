#include <bits/stdc++.h>
using namespace std;

void insertElement(int arr[], int &n, int value, int indx) {
    for (int i = n; i > indx; i--) {
        arr[i] = arr[i - 1];
    }
    arr[indx] = value;
    n++;
}

void deleteElement(int arr[], int &n, int indx) {
    for (int i = indx; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

int linearsearch(int arr[], int &n, int target){
    for (int i = 0; i < n; i++)
    {
        if(arr[i]== target) return i;
    }
    
}

int main() {
    int arr[100] = {1, 2, 3, 4, 5};
    int n = 5;

    insertElement(arr, n, 99, 2); 
    deleteElement(arr, n, 4);    

    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
