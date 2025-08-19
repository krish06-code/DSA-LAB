#include<iostream>
using namespace std;

int main(){
int arr[]= {1,2,2,3,3,4};
int n = sizeof(arr)/sizeof(arr[0]);
int i =0;
int cnt =0;
for(int j = 1 ; j<n; j++){
    if(arr[i]== arr[j]){
        continue;
        i=j;
    }
    else{
        cnt++;
    }
    i++;
}
cout<< cnt<<" ";
return 0;
}