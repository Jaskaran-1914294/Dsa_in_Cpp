#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node*left;
    node*right;
    node(int data){
        this->data=data;
    }
};
//Level wise Taking input
node*takeInput(){
    int rootData;
    cin>>rootData;
    node*root=new node(rootData);
    queue<node*>pending;
    pending.push(root);
    while(!pending.empty()){
        node*front=pending.front();
        pending.pop();
        int leftChildData,rightChildData;
        // cout<<"Enter left and right child of : "<<front->data;
        cin>>leftChildData>>rightChildData;
        if(leftChildData!=-1){
            node*leftChild=new node(leftChildData);
            front->left=leftChild;
            pending.push(leftChild);
        }
        if(rightChildData!=-1){
            node*rightChild=new node(rightChildData);
            front->right=rightChild;
            pending.push(rightChild);
        }
        cout<<endl;
    }
    return root;
}
//Level wise print
void print(node*root){
    queue<node*>pending;
    pending.push(root);
    while(!pending.empty()){
        node*front=pending.front();
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
        // cout<<endl;
    }
}
//Right View of Binary Tree BFS
vector<int> RightViewOfTreeByBFS(node*root){
    vector<int>ans;
    //Node,depth
    queue<node*>pending;
    pending.push(root);
    while(!pending.empty()){
        int n=pending.size();
        for(int i=0;i<n;i++){
            node*front=pending.front();
            pending.pop();
            if(i==n-1){
                ans.push_back(front->data);
            }
            if(front->left){
                pending.push(front->left);
            }
            if(front->right){
                pending.push(front->right);
            }
        }
    }
    return ans;
}
//Right View of a Tree DFS
void RightDFSHelper(node*root,int level,int &maxLevel,vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(level>maxLevel){
        maxLevel=level;
        ans.push_back(root->data);
    }
    RightDFSHelper(root->right,level+1,maxLevel,ans);
    RightDFSHelper(root->left,level+1,maxLevel,ans);
}
vector<int>RightViewofTreeDFS(node*root){
    vector<int>ans;
    if(root==NULL)return ans;
    int maxLevel=-1;
    RightDFSHelper(root,0,maxLevel,ans);
    return ans ;
}


//Left View of a Tree DFS (BFS is simple as earlier)
void LeftDFSHelper(node*root,int level,int &maxLevel,vector<int>&ans){
    if(root==NULL){
        return;
    }
    if(level>maxLevel){
        maxLevel=level;
        ans.push_back(root->data);
    }
    LeftDFSHelper(root->left,level+1,maxLevel,ans);
    LeftDFSHelper(root->right,level+1,maxLevel,ans);
}
vector<int> LeftViewofTreeBFS(node*root){
    int maxLevel=-1;
    vector<int>ans;
    LeftDFSHelper(root,0,maxLevel,ans);
    return ans;
}
//Top view of a Tree BFS (DFS not preffered as we have to save height too)
vector<int>TopViewOfTreeBFS(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>m;
    queue<pair<int,node*>>pending;
    // Level , node
    pending.push({0,root});
    while(!pending.empty()){
        auto l=pending.front();
        pending.pop();
        int line=l.first;
        node*front=l.second;
        if(m.find(line)==m.end()){
            m[line]=front->data;
        }
        if(front->left){
            pending.push({line-1,front->left});
        }
        if(front->right){
            pending.push({line+1,front->right});
        }
    }
    for(auto i:m){
        ans.push_back(i.second);
    }
    
    return ans;
}
//Bottom Views of Binary Tree BFS
vector<int>BottomViewOfTree(node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    map<int,int>m;
    queue<pair<int,node*>>pending;
    // Level , node
    pending.push({0,root});
    while(!pending.empty()){
        auto l=pending.front();
        pending.pop();
        int line=l.first;
        node*front=l.second;
        m[line]=front->data;
        if(front->left){
            pending.push({line-1,front->left});
        }
        if(front->right){
            pending.push({line+1,front->right});
        }
    }
      for(auto i:m){
        ans.push_back(i.second);
    }
    
    return ans;
}
int main(){
    node*root=takeInput();
    vector<int>rightView=RightViewofTreeDFS(root);
    vector<int>leftView=LeftViewofTreeBFS(root);
    vector<int>topView=TopViewOfTreeBFS(root);
    vector<int>bottomView=BottomViewOfTree(root);

    cout<<"Right View: ";
    for(auto i:rightView){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Left View: ";
    for(auto i:leftView){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Top View: ";
    for(auto i:topView){
        cout<<i<<" ";
    }
    cout<<endl;

    cout<<"Bottom View: ";
    for(auto i:bottomView){
        cout<<i<<" ";
    }
    cout<<endl;

}