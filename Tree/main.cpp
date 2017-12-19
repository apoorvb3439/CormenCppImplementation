#include<bits/stdc++.h>
#include"Tree.h"
using namespace std;

int main()
{
    Tree<string> *t=new Tree<string>("aba");
    t->insert("ab");
    t->insert("abc");
    t->insert("abab");

    t->print();
    t->height();
    
    return 0;
}
