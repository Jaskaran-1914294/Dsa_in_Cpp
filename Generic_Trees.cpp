#include<bits/stdc++.h>
using namespace std;
template<typename T>
class TreeNode{
    public:
        T data;
        vector<TreeNode<T>*>childrens;

    TreeNode(T data){
        this->data=data;
    }
};
//Print rootData and call recursion for next
void print(TreeNode<int>*root){
    if(root==NULL)return;
    cout<<root->data<<" : ";
    int n=root->childrens.size();
    for(int i=0;i<n;i++){
        cout<<root->childrens[i]->data<<",";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        print(root->childrens[i]);
    }
}
//Work for here and recursive part for down subtrees
TreeNode<int>*TakeInput(){
    cout<<"Enter data "<<endl;
    int rootData;
    cin>>rootData;
    TreeNode<int>*root=new TreeNode<int>(rootData);
    cout<<"Enter Number childs of "<<rootData<<": "<<endl;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        TreeNode<int>*child=TakeInput();
        root->childrens.push_back(child);
    }
    return root;
}
//Level order taking inputs
TreeNode<int>*TakeInputLevelWise(){
    int rootData;
    cout<<"Enter Root Data :"<<endl;
    cin>>rootData;
    TreeNode<int>*root=new TreeNode<int>(rootData);
    queue<TreeNode<int>*>pending;
    pending.push(root);
    //Push in Queue 
    while(pending.size()){
        //While Queue has elements in it 
        TreeNode<int>*front=pending.front();
        pending.pop();
        cout<<"Enter Number of Childrens of "<<front->data<<" : ";
        int numChild;
        cin>>numChild;
        for(int i=0;i<numChild;i++){
            int childData;
            cout<<"Enter "<<i<<" th Child of "<<front->data<<" : ";
            cin>>childData;
            TreeNode<int>*child=new TreeNode<int>(childData);
            //Push Each Child in the queue 
            front->childrens.push_back(child);
            pending.push(child);
        }
    }
    return root;
}
//Printing level order
void printLevelWise(TreeNode<int>*root){
    queue<TreeNode<int>*>pending;
    pending.push(root);
    while(pending.size()){
        TreeNode<int>*front=pending.front();
        pending.pop();
        cout<<front->data<<":";
        int n=front->childrens.size();
        for(int i=0;i<n;i++){
            cout<<front->childrens[i]->data<<",";
            pending.push(front->childrens[i]);
        }
        cout<<endl;
    }
}
//Printind Pre-order
void printPreOrder(TreeNode<int>*root){
    cout<<root->data<<" ";
    for(int i=0;i<root->childrens.size();i++){
        printPreOrder(root->childrens[i]);
    }
}
//Printing Post-Order
void printPostOrer(TreeNode<int>*root){
    if(root==NULL)return;
    for(int i=0;i<root->childrens.size();i++){
        printPostOrer(root->childrens[i]);
    }
    cout<<root->data<<" ";
}
//Counting Nodes
int countNodes(TreeNode<int>*root){
    int ans=1;
    for(int i=0;i<root->childrens.size();i++){
        ans+=countNodes(root->childrens[i]);
    }
    return ans;
}
int main(){
    
    /*TreeNode<int>*root=new TreeNode<int>(1);
    TreeNode<int>*a=new TreeNode<int>(2);
    TreeNode<int>*b=new TreeNode<int>(3);
    root->childrens.push_back(a);
    root->childrens.push_back(b);*/
    // 1 3 2 3 4 2 3 6 1 7 2 8 9 2 10 11 0 0 0 0 0 0

    TreeNode<int>*root=TakeInputLevelWise();
    cout<<endl;
    printPostOrer(root);
    cout<<countNodes(root)<<endl;
}