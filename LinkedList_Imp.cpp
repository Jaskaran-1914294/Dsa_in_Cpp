#include<bits/stdc++.h>
using namespace std;
//These are few important concept questions of linked lists

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
void display(node*temp){
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
//Reverse k-Nodes
node* reverseK(node*&head,int k){
    node*prev=NULL;
    node*curr=head;
    node*nextptr;
    int count =0;
    while(curr!=NULL && count<k){
      nextptr=curr->next;
      curr->next=prev;
      prev=curr;
      curr=nextptr;
      count++;
    }
    if(nextptr!=NULL){
        head->next=reverseK(nextptr,k);
    }
    return prev;

}
int main(){
node*head=NULL;
insert(head,1);
insert(head,2);
insert(head,3);
insert(head,4);
insert(head,5);
insert(head,6);
insert(head,7);
insert(head,8);
display(head);
//node* newHead=Reverse(head);
//display(newHead);
// node *byRec=Recursive_rev(head);
// display(byRec);
node*newHead=reverseK(head,2);
display(newHead);
}