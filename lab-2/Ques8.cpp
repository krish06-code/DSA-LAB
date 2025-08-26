#include<iostream>
using namespace std;

int main(){
    int arr[]= {1,2,2,3,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cnt = 1;  

    for(int j = 1 ; j<n; j++){
        if(arr[j] != arr[j-1]){
            cnt++;
        }
    }
    cout<< cnt << " ";
    return 0;
}
