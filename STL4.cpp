#include<iostream>
#include<set>
#include<vector>

using namespace std;

/*bool comparator(pair<int,int> p1, pair<int,int> p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;
    
    if(p1.first<p2.first) return true;
    else return false;
}*/


int main(){
    //++SETS
    /*set<int> s;//multiset<int>s;=It can take the duplicate values inside it 
    s.insert(3);
    s.emplace(4);
    s.emplace(5);
    s.insert(4);
    s.insert(7);
    cout<<s.size()<<endl;
    for(auto val:s){
        cout<<val<<" ";
    }*/
    
    //++UNORDERED_SET
    /*.For this, concept of lower and upper bound is not exist.
    .For this, values can be printed in any order(randomly)*/
    
    //++ALGORITHMS
   // #Sorting Algo
   /*int arr[5]={3,4,5,6,9};
   sort(arr,arr+5);
   sort(arr,arr+5,greater<int>());
   vector<int> v = {3,4,5,6,8};
   sort(v.begin(),v.end());
   sort(v.begin(), v.end(), greater<int>());
   
   for(int val:v){
       cout<<val<<" ";
   }*/
   
   //#Sorting wrt 'y' coordinate(using function)
   /*vector <pair<int,int>> v = {{3,4},{4,6},{7,4},{6,7}};
   sort(v.begin(),v.end(),comparator);
    for (auto p:v){
        cout<<p.first<<" "<<p.second<<endl;
    }*/
    
    //#Reversing order
    /*vector<int> v1={1,2,3,4,6,5};
    reverse(v1.begin()+4,v1.end()+5);
    for(auto val:v1){
        cout<<val<<" ";
    }
    cout<<endl;*/
    
    //#Next_Permutation
    /*string s = "abc";
    next_permutation(s.begin(),s.end());
    cout<<s<<endl;*/
    
    //#Swap
    /*int a=5,b=4;
    swap(a,b);
    cout<<"a="<<a<<endl;*/
    
    //#Binary search
    /*vector<int> v1={1,2,3,4,6,5};
    cout<<binary_search(v1.begin(),v1.end(),4)<<endl;*/
    
    
    return 0;  
}