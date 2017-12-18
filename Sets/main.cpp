#include<bits/stdc++.h>
#include "aset.h"
using namespace std;

int main(){
int n=-10;
Set s(n);

s.unione(1,3);
s.unione(7,10);
s.unione(-1,2);

s.find(-1);
return 0;
}
