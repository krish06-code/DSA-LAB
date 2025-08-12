#include<iostream>
using namespace std;

int main(){
int arr[]= {4,3,2,1};
int n = sizeof(arr)/sizeof(arr[0]);
int cnt =0;
for (int i = 0; i < n; i++)
{
    for (int j = i+1; j < n; j++)
    {
       if(arr[i]>arr[j]){
        cnt++;
       }
    }
    
}
cout<< cnt<<" ";

return 0;
}