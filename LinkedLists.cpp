#include<bits/stdc++.h>
using namespace std;
#define here cout<<" We Entered "<<endl;

//Linked lists
class node{
    public:
    int data;
    node*next;
    node(int a){
        data=a;
        next=NULL;
    }
};

//Create list Till it encounters -1
node* CreateList(){
    node*head=NULL;
    node*tail=NULL;
    int a;
    cin>>a;
    while(a!=-1){
        node*n=new node(a);
        if(head==NULL){
            head=n;
            tail=n;
        }
        else{
            tail->next=n;
            tail=tail->next;
        }
        cin>>a;
    }
    return head;
}

//Insert At Head
void insertAtHead(node*&head,int val){
    node*n=new node(val);
    n->next=head;
    head=n;
}

//Insert at tail 
void insertAtTail(node*&head,int val){
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
//Insert at i position
void insertAt(node*&head,int i,int val){
    node*n=new node(val);
    if(i==0){
        n->next=head;
        head=n;
        return;
    }
    int cnt=0;
    node*temp=head;
    while(temp!=NULL and cnt<i-1){
        temp=temp->next;
        cnt++;
    }
    if(temp!=NULL){
    n->next=temp->next;
    temp->next=n;
    }
}
//Insert node recursively
node* insertAtrex(node*head,int i,int data){
    if(head==NULL)return head;
    if(i==0){
        node*n=new node(data);
        n->next=head;
        head=n;
        return head;
    }
    else{
        head->next=insertAtrex(head->next,i-1,data);
        return head;
    }
}
//Palindromic linked list
bool isPalindrome(node*head){
    if(head==NULL or head->next==NULL){
        return 1;
    }
    node*other=NULL;
    node*temp=head;
    while(temp!=NULL){
        insertAtHead(other,temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        if(temp->data!=other->data){
            return 0;
        }
        temp=temp->next;
        other=other->next;
    }
    return 1;  
}
////////////////////////////
//Delete from head
void deleteAtHead(node*&head){
    if(head==NULL){
        return;
    }
    node*del=head;
    head=head->next;
    delete del;
}
//Delete from back
void deleteAtBack(node*&head){
    if(head==NULL or head->next==NULL){
        head=NULL;
        return;
    }
    node*temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}
//Delete at a position
void deleteAT(node*&head,int i){
    if(i==0){
        if(head==NULL){
            return;
        }
        head=head->next;
        return;
    }
    int cnt=0;
    node*temp=head;
    while(temp!=NULL and cnt<i-1){
        temp=temp->next;
        cnt++;
    }
    if(temp==NULL or temp->next==NULL){
        return;
    }
    temp->next=temp->next->next;
    return;
}
//Printing Linked List
void print(node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
//Delete Node Recursively
node* deleteAtRex(node*head,int i,int data){
    if(head==NULL){
        return head;
    }
    if(i==0){
        node*del=head;
        head=head->next;
        delete del;
        return head;
    }
    else{
        head->next=deleteAtRex(head->next,i-1,data);
        return head;
    }
}
//Append last N -nodes to front 
node*appendK(node*head,int n){
    if(head==NULL)return head;
    node*fast=head;
    node*slow=head;
    for(int i=0;i<n;i++){
        fast=fast->next;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    fast->next=head;
    head=slow->next;
    slow->next=NULL;
    return head;
}
//Delete Duplicate elements (1,1,1,2,2,3,3,4==1,2,3,4)
void RemoveDuplicate(node*&head){
    if(head==NULL or head->next==NULL){
        return;
    }
    while(head->next!=NULL and head->data==head->next->data){
        head=head->next;
    }
    RemoveDuplicate(head->next);
}

int main(){
    node* head=CreateList();
    print(head);

    // insertAtHead(head,23);
    // print(head);
    
    // insertAtTail(head,99);
    // print(head);

    // insertAt(head,0,12);
    // print(head);

    // insertAt(head,3,12);
    // print(head);
    
    // deleteAtBack(head);
    // print(head);
    
    // deleteAT(head,8);
    // print(head);

    // head=appendK(head,4);
    // print(head);
    RemoveDuplicate(head);
    print(head);

    return 0;
}