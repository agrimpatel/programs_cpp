#include<iostream>
using namespace std;

 int getDigit(const int p){
     if(p<10){
         return p;
     }else{
         return p%10+(p/10%10);
    }
 }
 int sumOddDigit(const string n){
     int sum =0;
     for(int i=n.size()-1;i>=0;i-=2){
         sum += n[i]-'0';
     }
     return sum;
     
 }
 int sumEvenDigit(const string n){
     int sum = 0;
     for(int i=n.size()-2;i>=0;i-=2){
         sum += getDigit((n[i]-'0')*2);
     }
     return sum;
 }
 
 int main(){
     string n;
     cout<<"Enter the Card number:";
     cin>>n;
     
     int result = 0;
     result = sumEvenDigit(n)+sumOddDigit(n);
     
     if(result%10 == 0){
         cout<<"Valid card number..";
     }else{
         cout<<"Invalid card number.";
     }
     
    // int getDigit(int n);
     
     
      return 0;
 }