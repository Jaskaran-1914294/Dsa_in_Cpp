#include<bits/stdc++.h>
using namespace std;

class node{
 public:
 int data;
 node*next;
 node(int val){
     data=val;
     next=NULL;
 }   
};
void insert(node*&head,int val){
    node*n=new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}
void show(node*temp){
while(temp!=NULL){
    cout<<temp->data<<"->";
    temp=temp->next;
}
cout<<"NULL"<<endl;
}

//Reverse a linked list
node* Reverse(node*&head){
    node*prevptr=NULL;
    node*currptr=head;
    node*nextptr;
    while(currptr!=NULL){
      nextptr=currptr->next;
      currptr->next=prevptr;

      prevptr=currptr;
      currptr=nextptr;
    }
    return prevptr;
}
node* Recursive_rev(node*&head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    node*newhead=Recursive_rev(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}
int main(){
node*head=NULL;
insert(head,1);
insert(head,2);
insert(head,3);
insert(head,4);
show(head);
//node* newHead=Reverse(head);
//show(newHead);
node *byRec=Recursive_rev(head);
show(byRec);
}