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
//Creation of a loop 
void createLoop(node*head,int pos){
    int count=1;
    node* n;
    node*temp=head;
    while(temp->next!=NULL){
        if(count==pos){
            n=temp;
        }
        temp=temp->next;
        count++;
    }
    temp->next=n;

}
//Detection of a loop in a linked list= FLoyd's Algo
bool checkLoop(node*head){
    node*fast=head;
    node*slow=head;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast){
            return 1;
        }
    }
    return 0;
}
//Deletion of a node
void deleteLoop(node*&head){
    node*fast=head;
    node*slow=head;
    do{
        fast=fast->next->next;
        slow=slow->next;
    }while(fast!=slow);
    fast=head;
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=NULL;
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
// display(head);
//node* newHead=Reverse(head);
//display(newHead);
// node *byRec=Recursive_rev(head);
// display(byRec);
// node*newHead=reverseK(head,2);
// display(newHead);
createLoop(head,3);
cout<<checkLoop(head)<<endl;
deleteLoop(head);
cout<<checkLoop(head);

}