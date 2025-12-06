#include<iostream>
#include<map>
using namespace std;

//Map is an associative array
int main(){
    map<string,int> marksMap;
    marksMap["Harry"] = 98;
    marksMap["Sam"] = 60;
    marksMap["Bob"] = 55;
    marksMap["Lia"] = 70;
    
    marksMap.insert({{"kozume",169},{"Kuroo",187}});
    map<string,int> :: iterator itr;
    for(itr=marksMap.begin();itr!=marksMap.end();itr++){
        cout<<(*itr).first<<" "<<(*itr).second<<"\n";
    }
    cout<<"Thr size is:"<<marksMap.size()<<endl;
    cout<<"Thr max size is:"<<marksMap.size()<<endl;
    cout<<"Thr empty's  return value is:"<<marksMap.size()<<endl;
    return 0;
}