#include<iostream>
#include<vector>
#include<list>
#include<deque>
using namespace std;
 int main(){
     //++VECTORS
     /*vector<int> v;
     vector<int> v1(3,10);//first place size and second place val 
     v.push_back(2);
     v.push_back(3);
     v.push_back(5);
     v.push_back(4);
     v.emplace_back(6);
     v.pop_back();
     v.erase(v.begin()); //erase index 1 ele
     v.insert(v.begin()+,100);
     cout<<v.size()<<endl;
     cout<<v.capacity()<<endl;
     cout<<v.front()<<endl;
     cout<<v.back()<<endl;
     cout<<"val at any idx:"<<" "<<v[2]<<endl;
     v.clear();
     v.empty();
     
      for(int val:v){
         cout<<val<<" ";
        }*/
        
     //++ITERATOR
     /*vector<int> v1 ={2,3,4,55,6,7,8,9};
     cout<<*(v1.begin())<<" ";
     cout<<*(v1.end())<<" ";
     vector<int>::iterator itr;
     //Forward iterator
     for(itr = v1.begin(); itr!=v1.end();itr++){
         cout<<*(itr)<<endl;
     }
     //Backward iterator
     for(itr = v1.rbegin(); itr!=v1.rend();itr++){
         cout<<*(itr)<<endl; 
     }*/
     
    //++LIST(doubly linked-list)
    /*list<int> l;
    l.push_back(4);
    l.push_back(3);
    l.emplace_back(2);
    l.push_back(1);
    l.push_front(6);
    l.emplace_front(8);
    l.emplace_front(10);
    l.pop_front();
    l.pop_back();
    list<int>::iterator it;
    for(it=l.begin();it!=l.end();it++){
        cout<<*(it)<<" ";
    }
    cout<<l[2];
    cout<<l.size()<<" ";
    */
    
    //++DEQUE(Dynamic Arrays)
    /*deque<int> d={1,2,3,4,6,5};
    for(int val:d){
        cout<<val<<" ";
    }
    cout<<d[2];*/
    
    //++PAIR
    vector<pair<int,int>> p = {{1,2}};
    pair<int,pair<char,int>> p1 = {1,{'a',3}};
    p.push_back({4,5});
    p.emplace_back(6,7);
    cout<<p[0].first<<" ";
    cout<<p1.second.first<<endl;
    
     return 0;
 }