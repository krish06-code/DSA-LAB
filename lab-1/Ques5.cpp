#include<iostream>
using namespace std;

int main(){
int arr[3][3] = {
    {1,2,3},
    {2,3,4},
    {4,5,6}
};
int sumr = 0;
int sumc = 0;
for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        sumr += arr[i][j];
        sumc += arr[j][i];
    }
    
}

cout<< sumr<<" "<<sumc<<" ";


return 0;
}