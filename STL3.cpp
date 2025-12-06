#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    //++STACK
    /*stack<int> s;
    s.push(44);
    s.push(24);
    s.emplace(56);
    s.emplace(43);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    
    stack<int> s1;
    
    s1.swap(s);
    cout<<s.size()<<endl;//0
    cout<<s1.size()<<endl;4*/
    
    //++QUEUE
    /*queue<int> q;
    q.push(3);
    q.push(4);
    q.emplace(5);
    cout<<"size :"<<q.size()<<endl;;
    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }*/
    
    //++P_QUEUE
   // priority_queue<int> p;//Largest value at top
   /* priority_queue<int,vector<int>,greater<int>> p;//for reverse sorted order
    p.push(5);
    p.push(6);
    p.push(8);
    p.push(0);
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }*/
    
    //++MAP(key,value pair)
    /*map<string,int> m;
    m["tv"] = 20;
    m["laptop"] = 20;
    m["headphones"] = 30;
    m["tablet"] = 40;
    m["watch"] = 50;
    
    m.insert("Camera",35);//m.emplace("Camera",35)
    
    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<"Count = "<<m.count("laptop")<<endl;
    
    if(m.find("Camera")!=m.end()){
         cout<<"Found\n";
    }else{
         cout<<"Not found\n";
    }*/
    
    /*multimap<string,int> m;
    m.emplace("TV",100);
    m.emplace("RADIO",70);
    m.emplace("MOBILE",69);
    m.emplace("LAPTOP",40);
    
    m.erase(m.find("TV"));
    
    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }*/
    
    /*unordered_map<string,int> m;
    //In this duplicate values is not allowed
    m.emplace("TV",100);
    m.emplace("RADIO",70);
    m.emplace("FRIDGE",69);
    m.emplace("WATCH",40);
    
    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl;
    }*/
    
    
    
    
    return 0;
}