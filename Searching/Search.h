#include<bits/stdc++.h>
using namespace std;

#ifndef ASEARCH_H
#define ASEARCH_H

template <typename OneD, typename T>
int lSearch(const OneD &arr, int n, T val){
try{
        for(int i=0;i<n;++i){
            if(arr[i]==val){
                return i;
            }
        }
    }catch(exception &e){
        cout<<"\nException caught : "<<e.what()<<endl;
    }
    return -1;
}


template <typename OneD, typename T>
int bSearch(const OneD &arr, int n, T val){
try{
        int l=0;
        int r=n-1;
        int mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(!(arr[mid]<val)&&!(val<arr[mid])/*arr[mid]==val*/){
                return mid;
            }
            if(val>arr[mid]){
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
    }catch(exception &e){
        cout<<"\nException caught : "<<e.what()<<endl;
    }
    return -1;
}

#endif
