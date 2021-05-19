#include<bits/stdc++.h>
using namespace std;
//Making Implementation of node
class node{
    public:
    int data;
    node * next;
    node(int a){
        data=a;
        next=NULL;
    }
};
//Insertions
void insertAtTail(node * &head,int val){
    node*n=new node(val);
    if(head==NULL){
        head=n;
        return ;
    }
    node *temp=head;
    while(temp->next!=NULL){
     temp=temp->next;
    }
    temp->next=n;   //n->next==null
}
void insertAtHead(node*&head,int v){
    node*n=new node(v);
    if(head==NULL){
        head=n;
        return;
    }
    n->next=head;
    head=n;
}
void insertBefore(node*&head,int before,int val){
    node*n=new node(val);
    node*temp=head;
    while(temp->next->data!=before){
        temp=temp->next;
    }
    n->next=temp->next;
    temp->next=n;
}

//Deletions
void deleteAtTail(node*&head){
    node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node*todelete=temp->next;
    temp->next=NULL;
    delete todelete;

}
void deleteAtHead(node*&head){
    node*todelete=head;
    head=head->next;
    delete todelete;

}
void deleteElement(node*&head,int element){
    node*temp=head;
    while(temp->next->data!=element){
        temp=temp->next;
    }
    node*todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

//Display the whole linked list
void display(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
 node*head=NULL;
 insertAtHead(head,1);
 insertAtHead(head,2);
 insertAtHead(head,3);
 insertAtTail(head,2);
 insertAtTail(head,3);
 display(head);
 deleteAtTail(head);
 display(head);
 deleteAtHead(head);
 display(head);
 deleteElement(head,1);
 display(head);
}