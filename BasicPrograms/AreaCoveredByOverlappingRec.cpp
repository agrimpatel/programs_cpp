#include<iostream>
#include<cmath>
using namespace std;

int RecArea(int X1 ,int Y1,int X2,int Y2){
    return abs(X2-X1)*abs(Y2-Y1);
}
bool isOverLapping(int X1, int Y1, int X2, int Y2,int X3,int Y3,int X4,int Y4){
    if(X2<=X3||X4<=X1) return false;
    if(Y2<=Y3||Y4<=Y1) return false;
    return true;
}

int main(){
    int x1,y1,x2,y2;
    int x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;

    if(x1 > x2) 
        swap(x1,x2);
    if (x3 > x4)
        swap(x3, x4);
    if (y1 > y2)
        swap(y1, y2);
    if (y3 > y4)
        swap(y3, y4);

    int area1 = RecArea(x1,y1,x2,y2);
    int area2 = RecArea(x3,y3,x4,y4);

    if (isOverLapping(x1, y1, x2, y2, x3, y3, x4, y4)){
        cout<<"YES"<<endl;
    
    int OlX1 = max(x1, x3);
    int OlX2 = min(x2, x4);
    int OlY1 = max(y1, y3);
    int OlY2 = min(y2, y4);

    int OverLapArea = RecArea(OlX1, OlX2, OlY1,OlY2);
    
    int TotalArea = area1+area2-OverLapArea;
    cout<<TotalArea<<endl;
    }else{
        cout<<"NO"<<endl;
        cout<<area1+area2<<endl; 
    }
    return 0;
}