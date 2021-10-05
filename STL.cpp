#include<bits/stdc++.h>
using namespace std;

class comp{
public:
    bool operator()(pair<int,string>p1,pair<int,string>p2){
     return (p1.first<p2.first);
    }
};

int main(){
    vector<int>v={1,2,1,4,1,6,3,4,9,1};
    set<int>s;
    for(auto i:v){
        s.insert(i);
    }
    for(auto i:s){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;
    //Tells the element strictly greater to that element (x>i)
    auto i=s.upper_bound(3);
    cout<<*i<<endl;

    //Tells the element equal to or greater than that (x>=j)
    auto j=s.lower_bound(3);
    cout<<*j<<endl;


    pair<int,string>p1=make_pair(100,"zaman");
    pair<int,string>p2=make_pair(109,"taran");
    pair<int,string>p3=make_pair(103,"dephj");
    pair<int,string>p4=make_pair(111,"wharh");
    pair<int,string>p5=make_pair(102,"whipz");

    multiset<pair<int,string> , comp >m;
    m.insert(p1);
    m.insert(p2);
    m.insert(p3);
    m.insert(p4);
    m.insert(p5);

    for(auto i: m){
        cout<<i.first<<" - "<<i.second<<endl;
    }
}