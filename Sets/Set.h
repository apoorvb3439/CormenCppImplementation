#include<bits/stdc++.h>
using namespace std;

#ifndef ASET_H
#define ASET_H

// class Set : ctor(int n) ie 0-n elems
// public fields : n, parent[n] & rank[n]
// public methods : find(x), link(x,y), unione(x,y)

class Set{

public:
    string str;
    // Size of Set
    int n;
    // parent arrray for each element
    int *parent;
    // rank arrray for height of each subtree rooted element
    int *rank;

    // ctor : Create parent and rank for n element set
    Set(int n){
        try{
            this->n=n;
            parent=new int[n];
            rank=new int[n];
            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=0;
            }
        }catch(exception &e){
            cout<<"\n!!!"<<"Exception Caught : [aset.h>>class SET>>ctor>>18:0] "<<e.what()<<"!!!"<<endl;
        }
    }

    // find the set containing x
    int find(int x){
        try{
            // throwing exception
            if(x<0||x>=n){
                throw runtime_error("Bad Find x<0||x>=n ");
            }
            // found the set reprsentative ie root of tree
            if(x==parent[x]){
                return x;
            }
            // Path Compression Heuristic
            parent[x]=find(parent[x]);
        }catch(exception &e){
            cout<<"\n!!!"<<"Exception Caught : [aset.h>>class SET>>find>>32:0] "<<e.what()<<"!!!"<<endl;
        }
        // return reprsentative
        return parent[x];
    }

    // link two elements x and y
    void link(int x, int y){
        try{
            // throwing exception
            if(x<0||x>=n||y<0||y>=n){
                throw runtime_error("Bad sets linking x<0||x>=n||y<0||y>=n ");
            }
            // Using Union Rank Heuristic
            if(rank[x]>rank[y]){
                parent[y]=x;
            }else{
                parent[x]=y;
                // Make x subtree of y
                if(rank[x]==rank[y]){
                    rank[y]=rank[y]+1;
                }
            }
        }catch(exception &e){
            cout<<"\n!!!"<<"Exception Caught : [aset.h>>class SET>>link>>48:0] "<<e.what()<<"!!!"<<endl;
        }

    }

    // union sets containing x and y
    bool unione(int x, int y)
    {
        try{
            // throwing exception
            if(x<0||x>=n||y<0||y>=n){
                throw runtime_error("Bad sets unione x<0||x>=n||y<0||y>=n ");
            }

            // find root of tree containing x
            int fx=find(x);
            // find root of tree containing y
            int fy=find(y);

            // if not in same set ie. tree
            if(fx!=fy){
                // link roots of both trees
                link(fx,fy);
    			return true;
    		}
        }catch(exception &e){
            cout<<"\n!!!"<<"Exception Caught : [aset.h>>class SET>>unione>>68:0] "<<e.what()<<"!!!"<<endl;
        }

        // unione applied on the same sets elems
		return false;
    }

};

#endif
