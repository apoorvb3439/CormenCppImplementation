#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& m)
{
    vector<vector<int>> v=m;
    int n=m.size();
    for(int i=0;i<m.size();++i){
        for(int j=0;j<m[i].size();++j){
            v[j][n-i-1]=m[i][j];
        }
    }


    for(int i=0;i<v.size();++i){
        for(int j=0;j<v[i].size();++j){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{

vector<vector<int>> v={{1,2,3},{4,5,6},{7,8,9}};

rotate(v);

return 0;
}
