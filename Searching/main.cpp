#include<bits/stdc++.h>
#include"Search.h"
using namespace std;

int main(){
    cout<<"Test"<<endl;
    int pos;
    string str;
    vector<string> arr={"apoorv","boy","gooze","goy","goz","toy"};

    do
    {
        for(auto s: arr){
            cout<<s<<",";
        }
        cout<<endl;
        cin>>str;
        pos=bSearch(arr,arr.size(),str);
        cout<<str<<" Pos : "<<pos<<endl;
        if(pos==-1)
            arr.push_back(str);
        sort(arr.begin(),arr.end(),less<string>());
    }while(true);


}
