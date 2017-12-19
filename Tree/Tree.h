#ifndef TREE_H
#define TREE_H

#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T val;
    Node *l;
    Node* r;
    Node()
    {
        l=NULL;
        r=NULL;
    }
    Node(T v)
    {
        this->val=v;
        l=NULL;
        r=NULL;
    }
};

template <typename T>
class Tree
{
public:
    Node<T>* root;
    Tree()
    {
        root=NULL;

    }
    Tree(T val){
        root=new Node<T>(val);
    }
	
void insert(T v);
bool search(T v);
void print();
void inorder(Node<T> *r);
int height();
bool searchR(Node<T> *r, T v);

private:
    void insertR(Node<T> *root,T v);
    int calcHeight(Node<T>* r);

};

template <typename T>
void Tree<T>:: insert(T v)
{
    if(root==NULL)
    {
        root=new Node<T>(v);

    }else
    {
        insertR(root,v);
    }
}

template <typename T>
void Tree<T>:: insertR(Node<T> *r,T v)
{
    if(v<r->val)
    {
        if(r->l==NULL)
        {
            r->l=new Node<T>(v);
        }else
        {
            insertR(r->l,v);
        }
    }
    else
    {
        if(r->r==NULL)
        {
            r->r=new Node<T>(v);
        }else
        {
            insertR(r->r,v);
        }
    }
}

template <typename T>
bool Tree<T> :: search(T v)
{
    if(searchR(root,v)) return true;
    return false;

}

template <typename T>
bool Tree<T> :: searchR(Node<T>* r,T v)
{
    if(r==NULL)
    {
        return false;
    }
    if(r!=NULL&&r->val==v)
    {
        return true;
    }
    if(r->l==NULL&&r->r==NULL){
        return false;
    }

    return (searchR(r->l,v)|searchR(r->r,v));
}

template <typename T>
void Tree<T> :: print()
{
    cout<<"{ ";
    inorder(root);
    cout<<"}\n";
}

template <typename T>
void Tree<T> :: inorder(Node<T> *r)
{
    if(r!=NULL){
        inorder(r->l);
        cout<<r->val<<", ";
        inorder(r->r);
    }

}

template <typename T>
int Tree<T> :: height()
{
    cout<<this->calcHeight(root);
}

template <typename T>
int Tree<T> :: calcHeight(Node<T>* r)
{
    if(r==NULL)
    {
        return -1;
    }
    else{
        int lh=calcHeight(r->l);
        int rh=calcHeight(r->r);
        if(lh>rh) return 1+lh;
        return 1+rh;

    }
}

#endif