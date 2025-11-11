#include<iostream>
using namespace std;

int main(){

int arr[] = {1,2,2,3,3,4};
int n = sizeof(arr)/sizeof(arr[0]);
int i =0;
for(int j =1; j<n;j++){
    if(arr[j]!= arr[i]){
        i++;
        arr[i] = arr[j];
    }
    else{
        continue;
    }

}

for(int k =0; k<=i; k++){
    cout<<arr[k]<<" ";
}

return 0;
}