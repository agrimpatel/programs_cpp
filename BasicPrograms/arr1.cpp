#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter Number of elements:";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cout<<"Enter Elements:";
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i];
    }
return 0;
}

