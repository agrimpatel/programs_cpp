#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<pair<int,int>> seg;
    seg.push_back(make_pair(2,5));
    seg.push_back(make_pair(4,8));
    seg.push_back(make_pair(9,12));

    int n= seg.size();
    vector<pair<int,bool>> points(n*2);
    for(int i=0;i<n;i++){
        points[i*2]=make_pair(seg[i].first,false);
        points[i*2+1]=make_pair(seg[i].second,true);
    }
    sort(points.begin(),points.end(),[](const pair<int,bool>& a,const pair<int,bool>& b)){
        return a.first<b.first||(a.first==b.first && !a.second);
    }
    int result=0;
    int counter=0;
    int last_position = points[0].first;

    for(int i=0;i<n*2;i++){
        if(counter>0){
            result += (points[i].first-last_position);
        }
        points[i].second?counter--:counter++;
        last_position = points[i].first;
        }
    cout<<result<<endl;
    return 0;


}
