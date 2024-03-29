#include<bits/stdc++.h>
using namespace std;
template<typename t>
class StackUsingArray{
    t *a;
    int n;
    int size;
    public:
    StackUsingArray(){
        size=2;
        n=0;
        a=new t(size);
    }
    void push(t x){
        if(n>=size){
            t *newarr=new t (size*2);
            for(int i=0;i<size;i++){
                newarr[i]=a[i];
            }
            size*=2;
            a[n]=x;
            n++;
        }
        else{
            a[n]=x;
            n++;
        }
    }
    void pop(){
        if(n==0){
            cout<<"Stack is Empty"<<endl;
            return;
        }
        n--;
    }
    bool isEmpty(){
        return (n==0);
    }
    int sizeOf(){
        return n;
    }
    t top(){
        if(n==0){
            cout<<"Stack is Empty"<<endl;
            return 0;
        }
        return a[n-1];
    }
};
template<typename t>
class node{
    public:
    t data;
    node<t>*next;
    node(t data){
        this->data=data;
        next=NULL;
    }
};
template<typename v>
class StackUsingLL{
    node<v>*head;
    int size;
    public:
    StackUsingLL(){
        head=NULL;
        size=0;
    }
    void push(v data){
        node<v>*n=new node<v>(data);
        size++;
        if(head==NULL){
            head=n;
            return;
        }
        n->next=head;
        head=n;
    }
    void pop(){
        if(size==0){
            cout<<"Empty stack"<<endl;
            return;
        }
        size--;
        node<v>*n=head;
        head=head->next;
        delete n;
    }
    v top(){
        if(size==0){
            cout<<"Stack is empty"<<endl;
            return 0;
        }
        return head->data;
    }
    bool empty(){
        return(size==0);
    }
    int sizeOf(){
        return size;
    }
};

class MinMaxStacks{
	vector<int>s;
	vector<int>min_stack;
	vector<int>max_stack;
public:
	MinMaxStacks(){
	}
	void push(int a){
		s.push_back(a);
		if(!min_stack.size() and !max_stack.size()){
			min_stack.push_back(a);
			max_stack.push_back(a);
			return;
		}
		//Place the element only when its greater and smaller than needed
		//Else placethe prev. element of stacks
		int curr_min=min_stack[min_stack.size()-1];
		int curr_max=max_stack[min_stack.size()-1];
		min_stack.push_back(min(curr_min,a));
		max_stack.push_back(max(curr_max,a));
	}
	void pop(){
		min_stack.pop_back();
		max_stack.pop_back();
		s.pop_back();
	}
	int getMax(){
		return max_stack[max_stack.size()-1];
	}
	int getMin(){
		return min_stack[min_stack.size()-1];
	}
};
 
//Stock Span Problem
void StockSpan(vector<int>a,int n,vector<int>&span){
    stack<int>s;
    s.push(0);
    span[0]=1;
    for(int i=1;i<n;i++){
        while(!s.empty() and a[s.top()]<a[i]){
            s.pop();
        }
        if(s.empty()){
            //Add the distance from starting to ith element
            span[i]=i+1;
        }
        else{
            //Add the distance of current top from ith element
            span[i]=i-s.top();
        }
        s.push(i);
    }    
}

//Largest Area Under Histogram - Monotonically Decreasing Stack ^_^_^
int LargestAreaUnderHistogram(vector<int>a,int n){
    stack<int>s;
    a.push_back(0);
    int ans=-1;
    for(int i=0;i<n;i++){
        //If Current element is greater than Stack top ,then just Place it
        if(!s.empty() and a[i]>a[s.top()]){
            s.push(i);
        }
        //Else find its perfect place to place it 
        else{
            int area=-1;
            int height=-1;
            while(!s.empty() and a[i]<a[s.top()]){
                height=a[s.top()];
                s.pop();
                //First formulae of area:- from the starting 
                if(s.empty()){
                    area=height*i;
                }
                //Normal formulare:- height*(high-low-1);
                else{
                    area=height*(i-s.top()-1);
                }
                ans=max(area,ans);
            }
            s.push(i);
        }
    }
    return ans;
}
//Reversing a stack from a helper stack
void reverse(stack<int>&a,stack<int>&b){
    if(a.empty())return;
    int top=a.top();
    a.pop();
    while(!a.empty()){
        b.push(a.top());
        a.pop();
    }
    reverse(b,a);
    a.push(top);
    while(!b.empty()){
        a.push(b.top());
        b.pop();
    }
}
int main(){
    // StackUsingArray<int> a;
    // a.push(12321);
    // a.push(12313);
    // a.push(98);
    // a.push(4342);
    // while(!a.isEmpty()){
    //     cout<<a.top()<<endl;
    //     a.pop();
    // }
    // cout<<"_____________________"<<endl;
    // StackUsingLL<int>b;
    // b.push(1);
    // b.push(2);
    // b.push(3);
    // cout<<b.top()<<endl;
    // b.pop();
    // b.pop();
    // cout<<b.top()<<endl;
    // b.pop();
    // b.pop();

    cout<<"STOCKSPAN Problem"<<endl;

    vector<int>a(7,0);
    int n=a.size();
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //{100,80,60,70,60,75,85};
    vector<int>span(7,0);
    StockSpan(a,n,span);
    for(int i=0;i<n;i++){
        cout<<span[i]<<" ";
    }
    cout<<endl;

    cout<<"LARGEST AREA UNDERHISTOGRAM"<<endl;
    // {6,2,5,4,5,1,6};
    vector<int> v(7);
	int m=v.size();
    for(int i=0;i<m;i++){
        cin>>v[i];
    }

	cout<<LargestAreaUnderHistogram(v,m)<<endl;
    cout<<"MIN MAX STACKS:-"<<endl;
    MinMaxStacks ms;
    ms.push(1);
    ms.push(5);
    ms.push(6);
    cout<<ms.getMax()<<" "<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.getMax()<<" "<<ms.getMin()<<endl;
    

    cout<<"Reversing stack with helper"<<endl;
    stack<int>st;
    stack<int>helper;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    reverse(st,helper);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
