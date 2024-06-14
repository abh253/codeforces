#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    int x;
    TrieNode*next[26];
    
    TrieNode(){
        x=0;
        for(int i=0;i<26;i++){
            next[i] = NULL;
        }
    }
};

class Trie{
    
    TrieNode*root;
    public:
    
    Trie(){
        root=new TrieNode;
    }

    void insert(string &s){
        TrieNode*temp=root;
        for(int i=0;i<s.length();i++){
            if(temp->next[s[i]-'a']==NULL){
                temp->next[s[i]-'a']=new TrieNode();
            }
            temp=temp->next[s[i]-'a'];
        }
        temp->x=temp->x+1;
    }

    int cnt(string &s){
        TrieNode*temp=root;
        for(int i=0;i<s.length();i++){
            if(temp->next[s[i]-'a']==NULL)return 0;
            temp=temp->next[s[i]-'a'];
        }
        return temp->x;

    }
};

int main(){

}
