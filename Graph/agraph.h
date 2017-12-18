#include<bits/stdc++.h>
using namespace std;

#ifndef AGRAPH_H
#define AGRAPH_H

// class Graph- ctor(n) : creates a graph of nXn with 0
//              ctor([][]adj, int n) : creates graph with adj matrix as adj
//              ctor(int **board, int n): creates graph with double pointer matrix
// fields - v : size of graph,
//          graph : graph in vector<vector>
// methods - add(x,y,defaultweight=1) : add directed edge from x to y
//           addU(x,y,defaultweight=1) : add Undirected edge from x to y
//           int **adj() : returns double pointer to graph adjacency matrix
// friend fn - print(g) : print the graphon consiole

class Graph{
public:
    int v;
    vector<vector<int>> graph;
    Graph(int n);

    template <typename TwoD>
    Graph(const TwoD &board, int n);

    Graph(int **board, int n);

    void add(int x, int y, int weight);
    void add(int x, int y);
    void addU(int x, int y, int weight);
    void addU(int x, int y);

    int** adj();

    friend void print(Graph g);

};

Graph:: Graph(int n){
    try{
        this->v=n;
        if(n<0){
            throw runtime_error("Bad Size: n<0 ");
        }
        for(int i=0; i<n; ++i){
            vector<int> vec(n,0);
            graph.push_back(vec);
        }
    }catch(exception &e){
        cout<<"\n!!!Exception caught : agraph.h>>class Graph>>ctor(int)>>40:00 "<<e.what()<<"!!!\n";
    }
}

template <typename TwoD>
Graph:: Graph(const TwoD &board, int n): Graph(n){
    try{
        for(int i=0; i<n; ++i){
            for(int j=0;j<n;++j){
                graph[i][j]=board[i][j];
            }
        }
    }catch(exception &e){
        cout<<"\n!!!Exception caught : agraph.h>>class Graph>>ctor(const TwoD&, int)>>49:00 "<<e.what()<<"!!!\n";
    }
}

Graph:: Graph(int **board, int n): Graph(n){
    try{
        for(int i=0; i<n; ++i){
            for(int j=0;j<n;++j){
                graph[i][j]=board[i][j];
            }
        }
    }catch(exception &e){
        cout<<"\n!!!Exception caught : agraph.h>>class Graph>>ctor(int** , int)>>65:00 "<<e.what()<<"!!!\n";
    }
}

void Graph:: add(int x, int y, int weight){
    try{
        if(x<0||x>=v||y<0||y>=v){
            throw runtime_error("Bad Vertices: x<0||x>=n||y<0||y>=n ");
        }
        graph[x][y]=weight;
    }catch(exception &e){
        cout<<"\n!!!Exception caught : agraph.h>>class Graph>>add(int,int,int)>>77:00 "<<e.what()<<"!!!\n";
    }
}

void Graph:: add(int x, int y){
    try{
        if(x<0||x>=v||y<0||y>=v){
            throw runtime_error("Bad Vertices: x<0||x>=n||y<0||y>=n ");
        }
        graph[x][y]=1;
    }catch(exception &e){
        cout<<"\n!!!Exception caught : agraph.h>>class Graph>>add(int,int)>>85:00 "<<e.what()<<"!!!\n";
    }
}

void Graph:: addU(int x, int y, int weight){
    try{
        if(x<0||x>=v||y<0||y>=v){
            throw runtime_error("Bad Vertices: x<0||x>=n||y<0||y>=n ");
        }
        graph[x][y]=weight;
        graph[y][x]=weight;
    }catch(exception &e){
        cout<<"\n!!!Exception caught : agraph.h>>class Graph>>addU(int,int,int)>>93:00 "<<e.what()<<"!!!\n";
    }
}

void Graph:: addU(int x, int y){
    try{
        if(x<0||x>=v||y<0||y>=v){
            throw runtime_error("Bad Vertices: x<0||x>=n||y<0||y>=n ");
        }
        graph[x][y]=1;
        graph[y][x]=1;
    }catch(exception &e){
        cout<<"\n!!!Exception caught : agraph.h>>class Graph>>addU(int,int)>>102:00 "<<e.what()<<"!!!\n";
    }
}

int** Graph:: adj(){
    try{
        int **board= new int*[v];
        for(int i=0; i<v; ++i){
            board[i]=new int[v];
            for(int j=0; j<v; ++j){
                board[i][j]=graph[i][j];
            }
        }
            return board;
    }catch(exception &e){
        cout<<"\n!!!Exception caught : agraph.h>>class Graph>>adj()>>111:00 "<<e.what()<<"!!!\n";
    }
    return nullptr;
}

void print(Graph g){
    try{
        for(int i=0; i<g.v; ++i){
            for(int j=0; j<g.v; ++j){
                cout<<g.graph[i][j]<<" ";
            }
            cout<<endl;
        }
    }catch(exception &e){
        cout<<"\n!!!Exception caught : agraph.h>>class Graph>>addU(int,int)>>126:00 "<<e.what()<<"!!!\n";
    }
}

#endif
