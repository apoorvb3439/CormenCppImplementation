#include<bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    fstream fout;
    fout.open("Out.txt");
    stringstream str("Hello World My Name is Apoorv");
    while(str>>line)
    {
        fout<<line<<" "<<flush;
    }
    fout.close();


    return 0;
}
