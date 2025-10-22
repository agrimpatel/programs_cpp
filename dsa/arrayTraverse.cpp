#include<iostream>
using namespace std;
int main(){
    int arr[] = {2,4,5,6,7,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}