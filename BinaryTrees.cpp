#include<bits/stdc++.h>
using namespace std;
template<typename T>
class BinaryTreeNode{
public:
    T data;
    BinaryTreeNode<int>*left;
    BinaryTreeNode<int>*right;
    BinaryTreeNode(T data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~BinaryTreeNode(){
        delete left;
        delete right;
    }
};
BinaryTreeNode<int>*TakeInput(){
    cout<<"Enter the data "<<endl;
    int rootData;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>*leftChild=TakeInput();
    BinaryTreeNode<int>*rightChild=TakeInput();
    root->left=leftChild;
    root->right=rightChild;
    return root;
}
void print(BinaryTreeNode<int>*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" : ";
    if(root->left){
        cout<<"Left= "<<root->left->data<<",";
    }
    if(root->right){
        cout<<"Right= "<<root->right->data;
    }
    cout<<endl;
    print(root->left);
    print(root->right);
}
BinaryTreeNode<int>* TakeInputLevelWise(){
    int rootData;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    queue<BinaryTreeNode<int>*>pending;
    BinaryTreeNode<int>*root=new BinaryTreeNode<int>(rootData);
    pending.push(root);
    while(!pending.empty()){
        BinaryTreeNode<int>*front=pending.front();
        pending.pop();
        // cout<<"Enter the left child of "<<front->data<<" : ";
        int leftChild;
        cin>>leftChild;
        if(leftChild!=-1){
            BinaryTreeNode<int>*LeftChildOfFront=new BinaryTreeNode<int>(leftChild);
            front->left=LeftChildOfFront;
            pending.push(LeftChildOfFront);
        }
        
        // cout<<"Enter the right child of "<<front->data<<" : ";
        int rightChild;
        cin>>rightChild;
        if(rightChild!=-1){
            BinaryTreeNode<int>*RightChildOfFront=new BinaryTreeNode<int>(rightChild);
            front->right=RightChildOfFront;
            pending.push(RightChildOfFront);
        }
        cout<<endl;
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int>*root){
    if(root==NULL)return;
    queue<BinaryTreeNode<int>*>pending;
    pending.push(root);
    while(!pending.empty()){
        BinaryTreeNode<int>*front=pending.front();
        pending.pop();
        cout<<front->data<<" : ";
        if(front->left){
            cout<<front->left->data<<" , ";
            pending.push(front->left);
        }
        if(front->right){
            cout<<front->right->data;
            pending.push(front->right);
        }
        cout<<endl;
    }
}
int makeSumTree(BinaryTreeNode<int>*root){
    if(root==NULL){
        return 0;
    }
    if(root->right==NULL and root->left==NULL){
        return root->data;
    }
    int temp=root->data;
    int a=makeSumTree(root->left);
    int b=makeSumTree(root->right);
    root->data=a+b;
    return (temp+a+b);
}
int main(){
     //Pre-Order  :- 1 2 4 -1 -1 5 -1 -1 3 -1 -1 
     //Level Order:- 1 2 3 4 5 -1 -1 -1 -1 -1 -1 
     //Post-Order :- 
     //       1
     //     /   \
     //    2     3
     //  /   \
     // 4     5
    BinaryTreeNode<int>*root=TakeInputLevelWise();
    makeSumTree(root);
    printLevelWise(root);
    /*
    For SumTree:-
    8 10 3 1 6 14 -1 -1 -1 9 7 13 -1 -1 -1 -1 -1 -1 -1 
    
    Solution:-
    63 : 23 , 27
    23 : 1 , 16
    27 : 13 , 
    1 : 
    16 : 9 , 7
    13 : 13 , 
    9 : 
    7 : 
    13 :

    */
    delete root;
}