#include<bits/stdc++.h>
using namespace std;
int manhattanDist(const vector<int>&p1,const vector<int>&p2){
    return abs(p1[0]-p2[0])+abs(p1[1]-p2[1])+abs(p1[2]-p2[2]);
}
int main(){
    vector<vector<int>> p={
        {2,3,4},
        {5,1,7},
        {3,2,6}
    };
    int minDist = INT_MAX;
    for(int i=0;i<p.size();i++){
        for(int j=i+1;j<p.size(),j++){
            minDist = min(minDist,manhattanDist(p[i],p[j]));
        }
    }
    cout<<minDst<<endl;
}