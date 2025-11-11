#include<bits/stdc++.h>
using namespace std;
int bs(int arr[],int value, int &n){
    sort(arr,arr+n);
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low +(high-low)/2;
        if(arr[mid]== value) return mid;
        else if( arr[mid]< value) low = mid +1;
        else{
            high = mid -1;
        }
    }
    return -1;
}

int main(){

    int arr[] = {1,55,78,96,69};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int index = bs(arr, 69, n);
    cout<< index<<" ";

return 0;
}