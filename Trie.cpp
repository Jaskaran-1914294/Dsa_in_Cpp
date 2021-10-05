#include<bits/stdc++.h>
using namespace std;
//TrieNode class for Alphabets
class TrieNode{
public:
    char data;
    TrieNode* *children;
    bool isTerminal;
    TrieNode(char data){
        this->data=data;
        children=new TrieNode*[26];
        isTerminal=0;
    }
};
//Trie Class
class Trie{
    TrieNode*root;
public:
    Trie(){
        root=new TrieNode('\0');
    }
    //TO INSERT AN ELEMENT IN A TRIE
    void insert(TrieNode*root,string word){
        if(word==""){
            root->isTerminal=1;
            return;
        }
        int index=word[0]-'a';
        TrieNode*child;
        if(root->children[index]){
            child=root->children[index];
        }
        else{
            root->children[index]=new TrieNode(word[0]);
            child=root->children[index];
        }
        insert(child,word.substr(1));
    }
    void insert(string word){
        insert(root,word);
    }
    //TO SEARCH A WORD IN TRIE
    bool search(TrieNode*root,string word){
        if(word==""){
            if(root->isTerminal){
                return 1;
            }
            else{
                return 0;
            }
        }
        int index=word[0]-'a';
        if(root->children[index]){
            return (search(root->children[index],word.substr(1)));
        }
        else{
            return 0;
        }
    }
    bool search(string word){
        return search(root,word);
    }
};
int main(){
    Trie root;
    root.insert("abc");
    root.insert("def");
    root.insert("hello");
    cout<<root.search("abc")<<endl;
    cout<<root.search("hello")<<endl;
    cout<<root.search("hel")<<endl;
}