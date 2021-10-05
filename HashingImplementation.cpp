#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout<<"X is : "<<x<<endl;
//Node Class For Each map block
template<typename T>
class node{
public:
    string key;
    T value;
    node*next;
    node(string key,T value){
        this->key=key;
        this->value=value;
    }
    ~node(){
        delete next;
    }
};
template<typename T>
void printList(node<T>*head){
    while(head){
        cout<<head->key<<"-"<<head->value<<",";
        head=head->next;
    }
    cout<<endl;
}
//Our Map
template <typename T>
class OurMap{
public:
    int bucketSize;
    int count;
    node<T>**bucket;
    OurMap(){
        bucketSize=5;
        count=0;
        bucket=new node<T>*[bucketSize];
        for(int i=0;i<bucketSize;i++){
            bucket[i]=NULL;
        }
    }
    ~OurMap(){
        for(int i=0;i<bucketSize;i++){
            delete bucket[i];
        }
        delete [] bucket;
    }
    int getSize(){
        return count;
    }
    int getHashCode(string key){
        int code=0;
        int coeff=1;
        for(int i=key.size();i>=0;i--){
            coeff=coeff%bucketSize;
            code+=coeff*key[i];
            coeff*=31;
            code=code%bucketSize;
        }
        return code % bucketSize;
    }
    void rehashing(){
        node<T>**temp=bucket;
        bucket=new node<T>*[bucketSize*2];
        int oldSize=bucketSize;
        bucketSize*=2;
        for(int i=0;i<oldSize*2;i++){
            bucket[i] = NULL;
        }
        for(int i=0;i<oldSize;i++){
            node<T> * head = temp[i];
            while(head){
                insert(head->key,head->value);
                head=head->next;
            }
        }
        for(int i=0;i<oldSize;i++){
            node<T>*head=temp[i];
            delete head;
        }
        
    }
    void insert(string key, T value){
        int hashCode=getHashCode(key);
        node<T>*head=bucket[hashCode];
        while(head!=NULL){
            if(head->key==key){
                head->value=value;
                return;
            }
            head=head->next;
        }
        head=bucket[hashCode];
        count++;
        node<T>*newNode = new node<T>(key,value);
        newNode->next=head;
        bucket[hashCode]=newNode;
        double loadFactor=(1.0*count)/bucketSize;
        if(loadFactor>0.7){
            rehashing();
        }
        return;
    }

    T erase (string key){
        int hashCode=getHashCode(key);
        node<T>*head=bucket[hashCode];
        node<T>*prev=NULL;
        while(head){
            if(head->key==key){
                T toReturn=head->value;
                if(prev==NULL){
                    // node<T>*toDelete=head;
                    head=head->next;
                    // toDelete->next=NULL;
                    // delete toDelete;
                }
                else{
                    node<T>*toDelete=head;
                    prev->next=head->next->next;
                    toDelete->next=NULL;
                    delete toDelete;
                }
                count--;
                return toReturn;
            }
            prev=head;
            head=head->next;
        }
        //Key Not Found 
        return 0;
    }
    T operator[](string key){
        int hashCode=getHashCode(key);
        node<T>*head=bucket[hashCode];
        while(head){
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;
    }
    void print(){
        for(int i=0;i<bucketSize;i++){
            node<T>*head=bucket[i];
            cout<<i<<" : ";
            printList(head);
            cout<<endl;
        }
    }

};

int main(){
    OurMap<int>m;
    m.insert("ABC",12);
    m.insert("DEF",12);
    // m.print();
    m.insert("GHUI",123);
    m.insert("Jaskaran",124);
    m.insert("WHAR",12);
    cout<<m.erase("Jaskaran");
    m.print();
}