#include<bits/stdc++.h>
using namespace std;
//Implementing generic search function
//template<class T>
//or
template<typename T>
int search(T arr[],int n,T key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

//Gegeric Programming on Containers in C++
template<class forwardItrerator,class V>
//We can take as much as class we need 
forwardItrerator doit(forwardItrerator start,forwardItrerator end,V key){
    while(start!=end){
        *start+=key;
        start++;
    }
    return end;
}
//Generic Making of a class function 
class car{
    public:
    string name;
    int price;
    car(){
        name="";
        price=0;
    }
    car(string s,int z){
        name=s;
        price=z;
    }
};
class Comparator{
    public:
    bool operator()(car a,car b){
        if(a.price==b.price){
            return 1;
        }
    return 0;
    }
};
template<class Iterator,class T,class compare>
Iterator search(Iterator start,Iterator end,T key,compare cmp){
    while(start!=end){
    	if(cmp(*start,key)){
    		return start;
    	}
    	start++;
    }
    return end;
}

int main(){
    // int a[]={1,2,3,4,5,6};
    // int n=6;
    // int key=4;
    // cout<<search(a,n,key)<<endl;      //Worked for int

    // float b[]={1.1,1.2,1.3,1.44};
    // int m=4;
    // float key1=1.3;
    // cout<<search(b,m,key1)<<endl;     //Worked for float

    //Making a generic function for containers
    // vector<int> v={1,2,3,4,5};
    // vector<int>::iterator it;
    // it=v.begin();
    // doit(it,v.end(),3);
    // for(auto i:v){
    //     cout<<i<<" ";
    // }
    // cout<<endl;

    //Works fine for arrays too
    // doit(a,a+n,12);
    // for(auto i:a){
    //     cout<<i<<" ";
    // }

    Comparator comp;
	vector<car>v;
	car a("Maruti",1000);
	car b("Maruti",3000);
	car c("Maruti",4000);
	car d("Maruti",80000);

	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	v.push_back(d);
	car key("Maruti",80300);
	if(search(v.begin(),v.end(),key,comp)!=v.end()){
		cout<<"Yes it is found"<<endl;
	}
	else{
		cout<<"OOPS"<<endl;
	}

}
