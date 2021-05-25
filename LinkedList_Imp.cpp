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
void check(int a[],int n,int k,int count){
   
   if(n==1){
	   count+=k;
	   cout<<count<<endl;
   }
   int diff=a[1]-a[0];
   if(diff<k){
     count+=diff;
	 check(a+1,n-1,k,count);
   }
   else{
	   count+=k;
	   check(a+1,n-1,k,count);
   }
   
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
int length(node*head){
	int n=0;
	while(head!=NULL){
		head=head->next;
		n++;
	}
	return n;
}
//Appending K-last nodes to front of a list
void kAppend(node*&head,int k){
   int l=length(head);
   node*newHead;
   node*newTail;
   node*tail=head;
   int count=1;
   while(tail->next!=NULL){
	   tail=tail->next;
	   if(count==l-k-1){
		   newTail=tail;
	   }
	   if(count==l-k){
		   newHead=tail;
	   }
	   count++;
   }
   tail->next=head;
   newTail->next=NULL;
   head=newHead;

}
//Create COmmon point of two nodes;

void createAt(node*&head1,node*head2,int pos){   //Assuming head1>head2;
    int count=1;
	node*temp=head1;
	while(count<pos){
		temp=temp->next;
        count++;
	}
    node*headofSecond=head2;
	while(headofSecond->next!=NULL){
     headofSecond=headofSecond->next;
	}
    headofSecond->next=temp;
}

int length(node*head){
	int ans=0;
	while(head!=NULL){
		ans++;
		head=head->next;
	}
	return ans;
}
//Comman element of two nodes
int isFoundAt(node*head1,node*head2){
   int l1=length(head1);
   int l2=length(head2);
   node*large;
   node*small;
   if(l1>l2){
	   large=head1;
	   small=head2;
   }
   else{
	   large=head2;
	   small=head1;
   }
   //large
   //small
   int diff=l1-l2;///////Maybe 
   while(diff--){
	   if(large->next==NULL){
		   return -1;
	   }
	   large=large->next;
   }
   while(large!=NULL && small!=NULL){
	   if(large->data==small->data){
		   return large->data;
	   }
	   large=large->next;
	   small=small->next;

   }
   return -1;
}
//for circular Linked list we just have to make next poiter of tail ==head
int main(){
// node*head=NULL;
// insert(head,1);
// insert(head,2);
// insert(head,3);
// insert(head,4);
// insert(head,5);
// insert(head,6);
// insert(head,7);
// insert(head,8);
// display(head);
// kAppend(head,3);
// display(head);
// cout<<length(head);
// node* newHead=Reverse(head);
// display(newHead);
// node *byRec=Recursive_rev(head);
// display(byRec);
// node*newHead=reverseK(head,2);
// display(newHead);
// createLoop(head,3);
// cout<<checkLoop(head)<<endl;
// deleteLoop(head);
// cout<<checkLoop(head);
//For checking common point:-
    node*head1=NULL;
	node*head2=NULL;
	insert(head1,1);
    insert(head1,2);
	insert(head1,3);
	insert(head1,4);
	insert(head1,5);
	insert(head1,6);
	insert(head1,7);
	insert(head2,8);
	insert(head2,9);
	createAt(head1,head2,5);

	display(head1);
	display(head2);
    cout<<isFoundAt(head1,head2);

}