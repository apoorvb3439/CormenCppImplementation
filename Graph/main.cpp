#include<bits/stdc++.h>
#include"agraph.h"
using namespace std;

int main()
{
	int board[3][3]={
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	Graph g(10);
	Graph b(board,3);

	g.add(1,2);
	b.addU(1,1,10);

	print(g);
	print(b);

	return 0;

}
