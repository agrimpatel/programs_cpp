#include<iostream>
using namespace std;
/*float fucAvg(int a,int b){
    float avg = (a+b)/2.0;
    return avg;
}
float fucAvg(int a,float b){
    float avg = (a+b)/2.0;
    return avg;
}*/
template <class T1,class T2>
float fucAvg(T1 a,T2 b){
    float avg = (a+b)/2;
    return avg;
}

template <class T>
void swap(T &a,T &b){
   T temp;
   temp = a;
   a = b;
   b = temp;
}



int main(){
    float a = fucAvg(3,4);
    cout<<a;
    
    int x =5,y =7;
    swap(x,y);
    cout<<x<<endl<<y;
    return 0;
}
